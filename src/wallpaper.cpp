#include "wallpaper.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

bool Wallpaper::load() {
    std::string path = std::string(getenv("HOME")) + "/.config/glpaper/shaders/default.frag";
    if (!std::filesystem::exists(path)) return false;

    std::ifstream file(path);
    if (!file.is_open()) return false;

    std::stringstream ss;
    ss << file.rdbuf();
    file.close();

    if (!shader.loadFromMemory(ss.str(), sf::Shader::Fragment)) return false;
    shader.setUniform("time", 0.f);

    rect.setSize({3440, 1440});
    return true;
}

void Wallpaper::update() {
    shader.setUniform("time", clock.getElapsedTime().asSeconds());
}

void Wallpaper::draw(sf::RenderWindow& window) const {
    window.draw(rect, &shader);
}
