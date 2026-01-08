#pragma once
#include <SFML/Graphics.hpp>

/**
 * @file window_manager.h
 * @brief Centralized manager responsible for creating and controlling the game window.
 *
 * Encapsulates SFML window creation, configuration and event handling,
 * providing a clean and minimal interface for the rest of the engine.
 */
class WindowManager {
public:
    /**
     * @brief Constructs and initializes the main render window.
     *
     * @param width  Window width in pixels.
     * @param height Window height in pixels.
     * @param title  Window title displayed in the title bar.
     */
    WindowManager(unsigned int width, unsigned int height, const std::string& title);

    /**
     * @brief Configures window runtime settings.
     *
     * @param fps            Target frame rate limit.
     * @param vsync          Enables or disables vertical synchronization.
     * @param repeatableKeys Enables or disables key repeat events.
     */
    void setupSettings(int fps, bool vsync, bool repeatableKeys);

    /**
     * @brief Processes window events and updates internal state.
     *
     * Must be called once per frame.
     */
    void update();

    /**
     * @brief Provides access to the underlying SFML render window.
     *
     * @return Reference to the internal sf::RenderWindow instance.
     */
    sf::RenderWindow& window();

    /**
     * @brief Checks whether the window is currently open.
     *
     * @return True if the window is open, false otherwise.
     */
    bool isOpen() const;

private:
    /**
     * @brief Sets the window icon from embedded resources.
     */
    void setIcon();

private:
    sf::RenderWindow renderWindow;
};
