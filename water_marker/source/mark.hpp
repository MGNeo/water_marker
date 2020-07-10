#pragma once

#include <SFML/Graphics.hpp>

class Mark
{
public:

  Mark(const std::string& filename);

  size_t GetWidth() const;
  size_t GetHeight() const;

  sf::Color GetPixel(const size_t x, const size_t y) const;

private:

  sf::Image Image;

};

