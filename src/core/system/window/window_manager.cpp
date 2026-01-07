#include "window_manager.h"

WindowManager::WindowManager(unsigned int width, unsigned int height, const std::string& title) : renderWindow(sf::VideoMode({width, height}), title) { }

sf::RenderWindow& WindowManager::window() {
    return renderWindow;
}

void WindowManager::setupSettings(int fps, bool vsync, bool repeatableKeys) {
    renderWindow.setFramerateLimit(fps);
    renderWindow.setVerticalSyncEnabled(vsync);
    renderWindow.setKeyRepeatEnabled(repeatableKeys);
}

void WindowManager::update() {
    
    while (const std::optional event = renderWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            renderWindow.close();
        }
    }
}


