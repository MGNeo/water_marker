#include "task.hpp"
#include "logger.hpp"

Task::Task()
  :
  WaterMark{ nullptr },
  LogoMark{ nullptr }
{
}

std::string Task::GetInputFileName() const
{
  return InputFileName;
}


void Task::SetWaterMark(const Mark& waterMark)
{
  WaterMark = &waterMark;
}

void Task::SetLogoMark(const Mark& logoMark)
{
  LogoMark = &logoMark;
}

void Task::SetInputFileName(const std::string& inputFileName)
{
  InputFileName = inputFileName;
}

void Task::SetOutputFileName(const std::string& outputFileName)
{
  OutputFileName = outputFileName;
}

void Task::Run()
{
  try
  {
    if (WaterMark == nullptr)
    {
      throw std::invalid_argument("Task::Run(), WaterMark == nullptr.");
    }

    if (LogoMark == nullptr)
    {
      throw std::invalid_argument("Task::Run(), LogoMark == nullptr.");
    }

    Image Image_;

    Image_.LoadFromFile(InputFileName);

    DrawWaterMark(Image_);
    DrawLogoMark(Image_);

    Image_.SaveToFile(OutputFileName);
  }
  catch (...)
  {
    Logger::Log("Task::Run(), " + GetInputFileName() + " could not be processed.");
    throw;
  }
  Logger::Log("Task::Run(), " + GetInputFileName() + " was successfully processed.");
}

void Task::DrawWaterMark(Image& image) const
{
  for (size_t px = 0; px < image.GetWidth() + WaterMark->GetWidth(); px += WaterMark->GetWidth())
  {
    for (size_t py = 0; py < image.GetHeight() + WaterMark->GetHeight(); py += WaterMark->GetHeight())
    {
      for (size_t mx = 0; mx < WaterMark->GetWidth(); ++mx)
      {
        for (size_t my = 0; my < WaterMark->GetHeight(); ++my)
        {
          const size_t ix = px - WaterMark->GetWidth() / 2 + mx;
          const size_t iy = py - WaterMark->GetHeight() / 2 + my;
          if ((ix < image.GetWidth()) && (iy < image.GetHeight()))
          {
            const sf::Color color = image.GetPixel(ix, iy) + WaterMark->GetPixel(mx, my);
            image.SetPixel(ix, iy, color);
          }
        }
      }
    }
  }
}

void Task::DrawLogoMark(Image& image) const
{
  for (size_t mx = 0; mx < LogoMark->GetWidth(); ++mx)
  {
    for (size_t my = 0; my < LogoMark->GetHeight(); ++my)
    {
      const size_t ix = image.GetWidth() - LogoMark->GetWidth() + mx;
      const size_t iy = image.GetHeight() - LogoMark->GetHeight() + my;
      if ((ix < image.GetWidth()) && (iy < image.GetHeight()))
      {
        const sf::Color color = LogoMark->GetPixel(mx, my);
        image.SetPixel(ix, iy, color);
      }
    }
  }
}