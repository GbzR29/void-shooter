#pragma once

#include "../entity.h"
#include "../projectiles/projectile.h"

class GameContext;

#include <cmath>
#include <vector>

/**
 * @class Player
 * @brief Represents the player-controlled spaceship entity.
 * * This class handles user input, movement physics (including screen clamping),
 * projectile management (Object Pooling), and multi-part sprite animations
 * (ship and thruster).
 */
class Player : public Entity {
    private:
        /** @brief Pointer to the global game context for audio and resources. */
        GameContext* ctx;

        // --- Thruster Animation ---
        /** @brief Sprite for the engine's fire effect. */
        sf::Sprite thruster_sprite;
        /** @brief Relative position of the thruster attached to the ship. */
        sf::Vector2f thruster_position;
        /** @brief Total number of frames in the thruster animation sequence. */
        const int thruster_total_frames = 4;
        /** @brief Timer to track animation progress. */
        float thruster_anim_time = 0;
        /** @brief Current active frame index for the thruster. */
        int thruster_actual_frame = 0;

        // --- Player Stats & Physics ---
        /** @brief The main ship sprite. */
        sf::Sprite player_sprite;
        /** @brief Constant speed of movement in pixels per second. */
        const float player_speed = 400.f;
        /** @brief Current health points of the player. */
        int player_hp = 10;
        /** @brief A vector2 to store the player's position */
        sf::Vector2f position;

        // --- Shooting System (Object Pool) ---
        /** @brief Collection of pre-allocated projectiles to avoid runtime allocations. */
        std::vector<Projectile> ammunition;
        /** @brief Maximum capacity of the ammunition pool. */
        int max_ammo = 20;     

    public:
        /**
         * @brief Constructs the player, loads textures, and initializes the projectile pool.
         * @param ctx Reference to the GameContext.
         */
        Player(GameContext& ctx);               
        
        /** @brief Virtual destructor ensuring proper cleanup. */
        virtual ~Player() = default;

        /**
         * @brief Updates player logic: movement, animations, and projectiles.
         * @param dt Delta time since last frame.
         */
        void update(float dt) override;

        /**
         * @brief Renders the player, thrusters, and all active projectiles.
         * @param window The SFML RenderWindow to draw on.
         */
        void draw(sf::RenderWindow& window) const override;

        /**
         * @brief Processes real-time keyboard input for continuous movement.
         * @param dt Delta time.
         */
        void input(float dt);

        /**
         * @brief Keeps the player sprite within the defined window boundaries.
         */
        void clampToScreen();

        /**
         * @brief Updates the thruster's texture rectangle for frame-based animation.
         * @param dt Delta time.
         */
        void animation(float dt);

        /**
         * @brief Finds an inactive projectile in the pool and fires it.
         * @param dt Delta time.
         */
        void shoot(float dt);

        // Retorna uma referência para o vetor de projéteis
        std::vector<Projectile>& getAmmunition() { return ammunition; }
        
        // Versão 'const' para quando você só precisar ler os dados sem alterar
        const std::vector<Projectile>& getAmmunition() const { return ammunition; }

        /**
         * @brief Handles discrete engine events (like one-tap key presses).
         * @param event The SFML event to process.
         * @param dt Delta time.
         */
        void handleEvent(const sf::Event& event, float dt);
};