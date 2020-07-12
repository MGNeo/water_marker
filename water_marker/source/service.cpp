#include "service.hpp"
#include "mark.hpp"
#include "image.hpp"
#include "task.hpp"
#include "task_pool.hpp"
#include "thread.hpp"

#include <filesystem>
#include <iostream>
#include <windows.h>
#include "logger.hpp"

void Service::Run()
{
  Logger::Log("Service::Run(), service was started.");

  {
    TaskPool taskPool;

    Mark waterMark(std::filesystem::current_path().string() + "\\marks\\water_mark.bmp");
    Mark logoMark(std::filesystem::current_path().string() + "\\marks\\logo_mark.bmp");

    std::filesystem::directory_iterator di{ std::filesystem::current_path().string() + "\\input" };
    for (auto& pi : di)
    {
      if (pi.is_directory() == false)
      {
        const std::string extention = pi.path().extension().string();
        if ((extention == ".jpg") || (extention == ".JPG"))
        {
          Task::Uptr task = std::make_unique<Task>();

          task->SetWaterMark(waterMark);
          task->SetLogoMark(logoMark);
          task->SetInputFileName(pi.path().string());
          task->SetOutputFileName(std::filesystem::current_path().string() + "\\output\\" + pi.path().filename().string());

          taskPool.Push(std::move(task));
        }
      }
    }

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    std::list<Thread::Uptr> threads;
    for (size_t i = 0; i < systemInfo.dwNumberOfProcessors; ++i)
    {
      auto thread = std::make_unique<Thread>(taskPool);
      threads.push_front(std::move(thread));
    }
  }

  Logger::Log("Service::Run(), service was finished.");
}