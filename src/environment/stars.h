#pragma once

#include "../core/game_context.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

/**
 * @class Stars
 * @brief Manages a background starfield effect with randomized positions and sizes.
 * * This class creates a particle-like system of stars that move vertically to 
 * simulate space travel. When a star leaves the bottom of the screen, it is 
 * repositioned at the top with a new random X coordinate.
 */
class Stars {   

    private:
        /** @brief Pointer to the global game context. */
        GameContext* ctx;

        // --- Random Number Generation (Modern C++) ---
        /** @brief Hardware-based random seed device. */
        std::random_device rd;
        /** @brief Mersenne Twister engine for high-quality random numbers. */
        std::mt19937 gen{ rd() };

        /** @brief Distribution for the horizontal axis (0 to Window Width). */
        std::uniform_real_distribution<float> distribX{ 0.f, 1200.f };
        /** @brief Distribution for the vertical axis (0 to Window Height). */
        std::uniform_real_distribution<float> distribY{ 0.f, 900.f };

        /** @brief Container holding the shapes of all generated stars. */
        std::vector<sf::CircleShape> stars;

        /**
         * @brief Internal helper to populate the star vector.
         * @param count The number of stars to create.
         */
        void create_stars(std::size_t count);

    public:
        /**
         * @brief Constructs the starfield.
         * @param ctx Reference to the GameContext.
         * @param count Total number of stars to render.
         */
        Stars(GameContext& ctx, std::size_t count);

        /**
         * @brief Renders all stars to the window.
         * @param window The SFML RenderWindow.
         */
        void draw(sf::RenderWindow& window);

        /**
         * @brief Updates the vertical position of each star.
         * @param delta_time Time elapsed since the last frame.
         */
        void update(float delta_time);
};