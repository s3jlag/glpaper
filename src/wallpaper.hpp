#pragma once
#include <SFML/Graphics.hpp>

class Wallpaper {
public:
    bool load();
    void update();
    void draw(sf::RenderWindow& window) const;

private:
    sf::Shader shader;
    sf::RectangleShape rect;
    sf::Clock clock;
};
