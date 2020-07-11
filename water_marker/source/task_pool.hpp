#pragma once

#include "task.hpp"

#include <list>
#include <mutex>
#include <optional>

class TaskPool
{
public:

  void Push(Task::Uptr&& task);
  Task::Uptr Pop();

private:

  std::mutex Mutex;
  std::list<Task::Uptr> Tasks;

};

