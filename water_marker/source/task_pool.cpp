#include "task_pool.hpp"

void TaskPool::Push(Task::Uptr&& task)
{
  if (task == nullptr)
  {
    throw std::invalid_argument("TskPool::Push(), tstk == nullptr.");
  }
  std::lock_guard<std::mutex> lock{ Mutex };
  Tasks.push_back(std::move(task));
}

Task::Uptr TaskPool::Pop()
{
  std::lock_guard<std::mutex> lock{ Mutex };
  if (Tasks.size() != 0)
  {
    auto task = std::move(Tasks.back());
    Tasks.pop_back();
    return std::move(task);
  } else {
    return nullptr;
  }
}