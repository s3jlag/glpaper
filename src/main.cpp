// src/main.cpp
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include "getwindow.hpp"

bool loadWallpaper(sf::RenderWindow* window); // forward declaration

int main() {
    spdlog::info("starting glpaper");

    sf::RenderWindow* window = getRenderWindow();
    if (!window) {
        spdlog::error("Failed to get render window");
        return 1;
    }

    if (!loadWallpaper(window)) {
        spdlog::error("Failed to load wallpaper");
        return 1;
    }

    return 0;
}
