#pragma once

#include <SFML/Graphics.hpp>

class Image
{
public:

  void LoadFromFile(const std::string& filename);
  void SaveToFile(const std::string& filename) const;

  size_t GetWidth() const;
  size_t GetHeight() const;

  sf::Color GetPixel(const size_t x, const size_t y) const;
  sf::Color SetPixel(const size_t x, const size_t y, const sf::Color color);

private:

  sf::Image Image_;

};

