#pragma once

#include "../entity.h"
#include <cmath>

// Forward declaration to reduce header dependency
class GameContext;

/**
 * @class Enemy
 * @brief Represents a basic hostile entity with automated movement patterns.
 * * This class inherits from Entity and implements a specific update logic 
 * that moves the enemy in a circular pattern using sine and cosine functions.
 */
class Enemy : public Entity {

    public:
        /**
         * @brief Constructs an Enemy and initializes its visual properties.
         * @param ctx Reference to the GameContext for accessing resources.
         */
        Enemy(GameContext& ctx);

        /**
         * @brief Updates the enemy's position based on a circular path.
         * @param dt Delta time since the last frame.
         */
        void update(float dt) override;

        /**
         * @brief Renders the enemy sprite to the provided window.
         * @param window The SFML RenderWindow to draw on.
         */
        void draw(sf::RenderWindow& window) const override;

        /**
         * @brief Handles the logic for firing projectiles.
         * @param dt Delta time for fire-rate calculations.
         */
        void shoot(float dt);

    private:    
        /** @brief Pointer to the global game context. */
        GameContext* ctx;

        /** @brief The visual representation of the enemy. */
        sf::Sprite enemy_sprite;

        /** @brief Base X coordinate (center of movement). */
        float enemy_x_position;

        /** @brief Base Y coordinate (center of movement). */
        float enemy_y_position;

        /** @brief Radius of the circular movement. */
        float amplitude;

        /** @brief Internal timer used to drive the sine/cosine oscillations. */
        float enemy_anim_time;
};