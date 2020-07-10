#include <iostream>

#include "service.hpp"

int main()
{
  // Нужна многопоточная обработка.
  
  /*
  std::filesystem::directory_iterator di("C:/Users/MGNeo/Desktop/water_marker/water_marker");

  for (auto e : di)
  {
    if (e.is_directory() == false)
    {
      std::cout << e.path().filename() << std::endl;
    }
  }

  */

  try
  {
    Service::Run("C:/Users/MGNeo/Desktop/water_marker/water_marker");
  }
  catch (const std::exception& e)
  {
    std::cout << "main(), std::exception was caught: " << e.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "main(), unknown exception was caught." << std::endl;
  }
  return 0;
}

