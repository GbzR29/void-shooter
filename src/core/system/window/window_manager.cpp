#include "window_manager.h"
#include "../../../assets/icon/icon.h"

WindowManager::WindowManager(unsigned int width, unsigned int height, const std::string& title)
: renderWindow(sf::VideoMode({width, height}), title) {}

sf::RenderWindow& WindowManager::window() {
    return renderWindow;
}

bool WindowManager::isOpen() const {
    return renderWindow.isOpen();
}

void WindowManager::setupSettings(int fps, bool vsync, bool repeatableKeys) {
    renderWindow.setFramerateLimit(fps);
    renderWindow.setVerticalSyncEnabled(vsync);
    renderWindow.setKeyRepeatEnabled(repeatableKeys);

    setIcon();
}

void WindowManager::setIcon() {
    sf::Image icon;

    if (!icon.loadFromMemory(icon_png, icon_png_len)) {
        return;
    }

    const auto size = icon.getSize();
    renderWindow.setIcon({size.x, size.y}, icon.getPixelsPtr());
}

void WindowManager::update() {
    while (const std::optional event = renderWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            renderWindow.close();
        }
    }
}

sf::Vector2u WindowManager::getSize(){
    return renderWindow.getSize();
}
