#pragma once
#include <SFML/Graphics.hpp>
#include "../core/system/resource/resource_manager.h"
#include "../core/game_context.h"

/**
 * @class UI
 * @brief Manages the User Interface (HUD) elements of the game.
 * * This class is responsible for displaying persistent information such as 
 * the player's health bar and current score. It acts as an overlay above 
 * the gameplay layer.
 */
class UI {

    private:
        /** @brief Pointer to the global game context for resource access. */
        GameContext* ctx;
       
        /** @brief Sprite used to represent the player's health visually. */
        sf::Sprite healthbar_sprite;

        /** @brief The font used for all UI text elements. */
        sf::Font default_font;

        /** @brief Text object for displaying the player's score. */
        sf::Text score_text;

    public:
        /**
         * @brief Constructs the UI, initializing fonts, texts, and bar textures.
         * @param ctx Reference to the GameContext.
         */
        UI(GameContext& ctx);

        /**
         * @brief Renders all UI elements to the screen.
         * @note This should be called last in the draw cycle to ensure the UI stays on top.
         * @param window The SFML RenderWindow.
         */
        void draw(sf::RenderWindow& window);

        /**
         * @brief Updates UI logic, such as dynamic health bar size or score counting.
         * @param dt Delta time.
         */
        void update(float dt);
};