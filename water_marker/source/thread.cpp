#include "thread.hpp"
#include "logger.hpp"

Thread::Thread(TaskPool& taskPool)
  :
  TaskPool_{ taskPool }
{
  Future = std::async(&Thread::Run, this);
}

void Thread::Run()
{
  
  while (true)
  {
    try
    {
      auto task = TaskPool_.Pop();
      if (task != nullptr)
      {
        task->Run();
      } else {
        break;
      }
    }
    catch (const std::exception & e)
    {
      Logger::Log("Thread::Run(), std::exception was caught: " + std::string(e.what()));
    }
    catch (...)
    {
      Logger::Log("THread::Run(), unknown exception was caught.");
    }
  }
}