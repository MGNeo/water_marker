#include "image.hpp"

void Image::LoadFromFile(const std::string& filename)
{
  if (Image_.loadFromFile(filename) == false)
  {
    throw std::runtime_error("Image::LoadFromFile(), image could not be loaded from file: " + filename);
  }
  if (GetWidth() == 0)
  {
    throw std::runtime_error("Image::LoadFromFile(), GetWidth() == 0.");
  }
  if (GetHeight() == 0)
  {
    throw std::runtime_error("Image::LoadFromFile(), GetHeight()== 0.");
  }
}

void Image::SaveToFile(const std::string& filename) const
{
  if (Image_.saveToFile(filename) == false)
  {
    throw std::runtime_error("Image::SaveToFile(), image could not be saved to file: " + filename);
  }
}

size_t Image::GetWidth() const
{
  return Image_.getSize().x;
}

size_t Image::GetHeight() const
{
  return Image_.getSize().y;
}

sf::Color Image::GetPixel(const size_t x, const size_t y) const
{
  if (x >= GetWidth())
  {
    throw std::invalid_argument("Image::GetPixel(), x >= GetWidth().");
  }
  if (y >= GetHeight())
  {
    throw std::invalid_argument("Image::GetPixel(), y >= GetHeight.");
  }
  return Image_.getPixel(x, y);
}

sf::Color Image::SetPixel(const size_t x, const size_t y, const sf::Color color)
{
  if (x >= GetWidth())
  {
    throw std::invalid_argument("Image::SetPixel(), x >= GetWidth().");
  }
  if (y >= GetHeight())
  {
    throw std::invalid_argument("Image::SetPixel(), y >= GetHeight().");
  }
  Image_.setPixel(x, y, color);
}

