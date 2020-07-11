#pragma once

#include "task_pool.hpp"
#include <future>

class Thread
{
public:

  using Uptr = std::unique_ptr<Thread>;

  Thread(TaskPool& taskPool);

private:

  std::future<void> Future;
  TaskPool& TaskPool_;

  void Run();

};

