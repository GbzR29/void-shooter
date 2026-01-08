#pragma once
#include <SFML/Graphics.hpp>

class WindowManager {
public:
    WindowManager(unsigned int width, unsigned int height, const std::string& title);
    void setupSettings(int fps, bool vsync, bool repeatableKeys);

    void update();

    sf::RenderWindow& window();

    // getters
    sf::RenderWindow& getRenderWindow() { return renderWindow; }
    bool isOpen() const { return renderWindow.isOpen(); }

    void setIcon();


private:
    sf::RenderWindow renderWindow;
};
