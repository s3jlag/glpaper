// wallpaper.cpp

#include "wallpaper.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>

bool Wallpaper::load(const std::string& fragPath) {
    std::ifstream file(fragPath);
    if (!file.is_open()) {
        spdlog::error("Failed to open shader file: {}", fragPath);
        return false;
    }

    std::stringstream ss;
    ss << file.rdbuf();
    std::string fragSource = ss.str();

    if (!shader.loadFromMemory(fragSource, sf::Shader::Type::Fragment)) {
        spdlog::error("Failed to compile shader from file: {}", fragPath);
        return false;
    }

    clock.restart();
    return true;
}

void Wallpaper::update() {
    shader.setUniform("time", clock.getElapsedTime().asSeconds());
}

void Wallpaper::draw(sf::RenderTarget& target) const {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(target.getSize()));
    rect.setFillColor(sf::Color::White);
    target.draw(rect, &shader);
}
