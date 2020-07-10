#include "service.hpp"
#include "mark.hpp"
#include "image.hpp"
#include "task.hpp"

#include <filesystem>
#include <iostream>

void Service::Run(const std::string& directory)
{
  std::list<Task::Uptr> tasks;

  Mark waterMark(directory + "/marks/water_mark.jpg");
  Mark logoMark(directory + "/marks/logo_mark.jpg");

  std::filesystem::directory_iterator di{ directory + "/input" };
  for (auto& pi : di)
  {
    if (pi.is_directory() == false)
    {
      if (pi.path().extension().string() == ".jpg")
      {
        Task::Uptr task = std::make_unique<Task>();
        task->SetWaterMark(waterMark);
        task->SetLogoMark(logoMark);
        task->SetInputFileName(pi.path().string());
        task->SetOutputFileName(directory + "/output/" + pi.path().filename().string());
        task->Run();        // Debug.
        tasks.push_front(std::move(task));
      }
    }
  }
}