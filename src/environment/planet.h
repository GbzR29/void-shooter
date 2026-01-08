#pragma once
#include <SFML/Graphics.hpp>
#include "../core/game_context.h"

/**
 * @class Planet
 * @brief Manages a decorative, animated planet in the background.
 * * This class handles a complex sprite sheet animation with a high frame count
 * to create a smooth visual effect. It resides in the background layer 
 * of the game environment.
 */
class Planet {

    private:
        /** @brief Pointer to the global game context for resource access. */
        GameContext* ctx;

        /** @brief The visual representation of the planet. */
        sf::Sprite earth_sprite;

        /** @brief Internal timer to track animation progress. */
        float earth_anim_time = 0.f;    
        /** @brief Total number of frames available in the planet's sprite sheet. */
        const int earth_total_frames = 163;
        /** @brief Current active frame index. */
        int earth_actual_frame = 0;

    public:
        /**
         * @brief Constructs the Planet and sets its initial visual properties.
         * @param ctx Reference to the GameContext.
         */
        Planet(GameContext& ctx);

        /**
         * @brief Updates the animation frame based on elapsed time.
         * @param dt Delta time.
         */
        void update(float dt);

        /**
         * @brief Renders the planet to the screen.
         * @param window The SFML RenderWindow.
         */
        void draw(sf::RenderWindow& window);
};