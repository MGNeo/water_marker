#include "logger.hpp"

#include <iostream>

std::mutex Logger::Mutex;

void Logger::Log(const std::string& message)
{
  std::lock_guard<std::mutex> lock{ Mutex };
  std::cout << message << std::endl;
}