#pragma once
#include "../entity.h"
#include <iostream>

/**
 * @class Projectile
 * @brief Represents a single bullet or laser bolt.
 * * Designed to be used within an Object Pool. Projectiles are not destroyed;
 * they are toggled between active and inactive states to save CPU cycles.
 */
class Projectile : public Entity {

    private:
        /** @brief Current 2D coordinates of the projectile. */
        sf::Vector2f position{0.f, 0.f};
        /** @brief Movement vector (direction and speed). */
        sf::Vector2f velocity{0.f, 0.f};

        /** @brief Internal state for the Object Pool management. */
        bool active = false;

        /** @brief The projectile's visual sprite. */
        sf::Sprite projectile_sprite;

        /** @brief Pointer to store the address of the entity that the projectile collided with. */
        Entity* collided_entity;

    public:
        /**
         * @brief Constructs a projectile and sets its texture.
         * @param rm Reference to the ResourceManager.
         */
        Projectile(ResourceManager& rm);

        /**
         * @brief Resets and launches the projectile from a specific point.
         * @param startPos The initial position (usually the ship's muzzle).
         * @param vel The velocity vector for the flight path.
         */
        void activate(sf::Vector2f startPos, sf::Vector2f vel);

        /**
         * @brief Status check for the pool manager.
         * @return True if the projectile is currently in flight.
         */
        bool isActive() const { return active; }

        /**
         * @brief Updates the flight position and checks for screen boundaries.
         * @param dt Delta time.
         */
        void update(float dt) override;

        /**
         * @brief Renders the projectile if it is active.
         * @param window The SFML RenderWindow.
         */
        void draw(sf::RenderWindow& window) const override;

        /**
         * @brief Check if the projectile collided with any entity.
         * @param entity It receives a reference to an entity and stores its attributes.
         */
        void onCollision(Entity& entity);

        
};