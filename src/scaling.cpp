#include "scaling.hpp"
#include <SFML/Graphics.hpp>

void scale_horizontal_fit(sf::RenderWindow* window, sf::Sprite* wallpaper_sprite) {
  auto win_size = sf::Vector2f(window->getSize());
  auto tex_size = sf::Vector2f(wallpaper_sprite->getTexture().getSize());

  float scale = win_size.x / tex_size.x;
  float y_offset = (win_size.y - tex_size.y * scale) / 2.f;

  wallpaper_sprite->setScale({scale, scale});
  wallpaper_sprite->setPosition({0.f, y_offset});
}

void scale_vertical_fit(sf::RenderWindow* window, sf::Sprite* wallpaper_sprite) {
  auto win_size = sf::Vector2f(window->getSize());
  auto tex_size = sf::Vector2f(wallpaper_sprite->getTexture().getSize());

  float scale = win_size.y / tex_size.y;
  float x_offset = (win_size.x - tex_size.x * scale) / 2.f;

  wallpaper_sprite->setScale({scale, scale});
  wallpaper_sprite->setPosition({x_offset, 0.f});
}

void scale_stretched(sf::RenderWindow* window, sf::Sprite* wallpaper_sprite) {
  auto win_size = sf::Vector2f(window->getSize());
  auto tex_size = sf::Vector2f(wallpaper_sprite->getTexture().getSize());

  float x_scale = win_size.x / tex_size.x;
  float y_scale = win_size.y / tex_size.y;

  wallpaper_sprite->setScale({x_scale, y_scale});
  wallpaper_sprite->setPosition({0.f, 0.f});
}
