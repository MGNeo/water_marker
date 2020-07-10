#pragma once

#include <string>

class Service
{
public:

  static void Run(const std::string& directory);

private:

  Service() = delete;

  Service(const Service& service) = delete;
  Service(Service&& service) = delete;

  void operator=(const Service& service) = delete;
  void operator=(Service&& service) = delete;

  ~Service() = delete;

};

