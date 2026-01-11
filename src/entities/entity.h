#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "../core/system/resource/resource_manager.h"

/**
 * @class Entity
 * @brief Abstract base class for all interactive game objects.
 * * This interface defines the standard life cycle of a game object:
 * Input -> Update -> Draw. It uses virtual methods to ensure that derived 
 * classes (Player, Enemy, Projectile) implement their own specific logic.
 */
class Entity {

public:
    /** @brief Default constructor for Entity. */
    Entity() = default;

    /** @brief Virtual destructor to ensure proper cleanup of derived classes. */
    virtual ~Entity() = default;

    /**
     * @brief Optional: Handles specific SFML events.
     * @param ev The SFML event to be processed.
     */
    virtual void handleInput(const sf::Event& ev) {} 

    /**
     * @brief Mandatory: Pure virtual function to update object logic.
     * @param dt Delta time since the last frame.
     */
    virtual void update(float dt) = 0; 

    /**
     * @brief Mandatory: Pure virtual function to render the object.
     * @param window The SFML RenderWindow to draw on.
     */
    virtual void draw(sf::RenderWindow& window) const = 0;

    /**
     * @brief Checks if the entity is currently active/alive.
     * @return True if alive, false otherwise.
     */
    bool isAlive() const { return alive; }

    /**
     * @brief Marks the entity as dead, typically for removal from a system.
     */
    void kill() { alive = false; }  

    /**
     * @brief It modifies the entity's attributes when it takes damage.
     */
    virtual void takeDamage(int amount) {}

    /**
     * @brief Defines a collision box for the entity.
     */
    sf::FloatRect collision_box;

protected:
    /** @brief Flag indicating the entity's status. */
    bool alive = true;
};