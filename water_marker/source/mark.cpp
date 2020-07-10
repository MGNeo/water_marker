#include "mark.hpp"

Mark::Mark(const std::string& filename)
{
  if (Image.loadFromFile(filename) == false)
  {
    throw std::runtime_error("Mark::Mark(), image could not be loaded: " + filename);
  }
  if (GetWidth() == 0)
  {
    throw std::runtime_error("Mark::Mark(), GetWidth() == 0.");
  }
  if (GetHeight() == 0)
  {
    throw std::runtime_error("Mark::Mark(), GetHeight() == 0.");
  }
}

size_t Mark::GetWidth() const
{
  return Image.getSize().x;
}

size_t Mark::GetHeight() const
{
  return Image.getSize().y;
}

sf::Color Mark::GetPixel(const size_t x, const size_t y) const
{
  if (x >= GetWidth())
  {
    throw std::invalid_argument("Mark::GetPixel(), x >= GetWidth().");
  }
  if (y >= GetHeight())
  {
    throw std::invalid_argument("Mark::GetPixel(), y >= GetHeight().");
  }
  return Image.getPixel(x, y);
}