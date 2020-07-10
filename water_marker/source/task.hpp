#pragma once

#include "mark.hpp"
#include "image.hpp"

class Task
{
public:

  using Uptr = std::unique_ptr<Task>;

  Task();

  void SetWaterMark(const Mark& waterMark);
  void SetLogoMark(const Mark& logoMark);

  void SetInputFileName(const std::string& inputFileName);
  void SetOutputFileName(const std::string& outputFileName);

  void Run();

private:

  const Mark* WaterMark;
  const Mark* LogoMark;

  std::string InputFileName;
  std::string OutputFileName;

  void DrawWaterMark(Image& image) const;
  void DrawLogoMark(Image& image) const;

};

