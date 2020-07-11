#pragma once

#include <string>
#include <mutex>

class Logger
{
public:

  static void Log(const std::string& message);

private:

  static std::mutex Mutex;

  Logger() = delete;

  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;

  void operator=(const Logger&) = delete;
  void operator=(Logger&) = delete;

  ~Logger() = delete;

};

