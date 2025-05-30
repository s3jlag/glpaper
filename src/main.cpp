#include <SFML/Graphics.hpp>
#include "wallpaper.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({3440, 1440}), "", sf::Style::None);
    Wallpaper wallpaper;
    wallpaper.load();

    while (window.isOpen()) {
        if (auto e = window.pollEvent()) {
            if (e->is<sf::Event::Closed>()) window.close();
        }

        wallpaper.update();
        window.clear();
        wallpaper.draw(window);
        window.display();
    }

    return 0;
}
