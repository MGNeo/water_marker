#include <iostream>
#include <Windows.h>

#include "logger.hpp"
#include "service.hpp"

int main(int argc, char** argv)
{
  try
  {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Service::Run();
  }
  catch (const std::exception& e)
  {
    Logger::Log("main(), std::exception was caught: " + std::string(e.what()));
  }
  catch (...)
  {
    Logger::Log("main(), unknown exception was caught.");
  }
  (void)getchar();
  return 0;
}