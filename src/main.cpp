/**
 * @file main.cpp
 * @brief Entry point for the Void Shooter game.
 * * This file handles the high-level orchestration of the engine's core systems.
 * It ensures that the Window, Resource, and Audio managers are initialized 
 * in the correct order before passing them to the Game Context.
 * * @author Gabriel Carvalho
 * @date 2026
 */

#include <SFML/Graphics.hpp>
#include "game/game.h"
#include <iostream>

/**
 * @brief Main function.
 * * This function initializes the base systems and starts the game loop.
 * * **Initialization Order:**
 * 1. WindowManager (Graphic context)
 * 2. ResourceManager (Asset loading)
 * 3. AudioManager (Sound system)
 * 4. GameContext (Service Locator)
 * 5. Game (Main logic)
 * * @return int Returns 0 upon successful termination.
 */
int main() {
    try {
        // 1. Instantiate the window system
        WindowManager window(1280, 720, "Void Shooter");
        window.setupSettings(120, true, false);

        // 2. Instantiate resources (Must exist as long as the game is running)
        ResourceManager rm;
        AudioManager audio(rm);

        // 3. Set up the GameContext (Standardized package for system access)
        // Using an initializer list for the struct
        GameContext ctx{ &window, &rm, &audio };

        // 4. Start the game orchestration
        Game game(ctx);
        game.run();
        
    } catch (const std::exception& e) {
        // Basic error handling for critical initialization failures
        std::cerr << "Critical Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}