// src/wallpaper.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Wallpaper {
public:
    sf::Vector2u resolution;
    sf::Shader shader;

    bool load(const std::string& path);
    void update(float time);
    void draw(sf::RenderTarget& target) const;
};
