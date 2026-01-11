#pragma once

#include "../core/game_context.h"
#include "../entities/player/player.h"
#include "../entities/enemy/enemy.h"
#include "../environment/stars.h"
#include "../environment/planet.h"
#include "../ui/ui.h"

#include <vector>

/**
 * @class Game
 * @brief The main controller class that manages the core game loop and systems coordination.
 * * This class is responsible for initializing all game entities, processing inputs,
 * updating the game logic every frame, and orchestrating the rendering process.
 */
class Game {
public:
    /**
     * @brief Constructs the Game instance and initializes all core entities.
     * @param ctx Reference to the GameContext containing shared engine systems.
     */
    Game(GameContext& ctx);

    /**
     * @brief Starts and maintains the main game loop.
     * * This function contains the logic for delta time calculation, event polling,
     * the update cycle, and the draw cycle. It only returns when the window is closed.
     */
    void run();

private:
    /** @brief Reference to the shared context (Audio, Window, Resources). */
    GameContext& ctx;

    /** @brief The player's ship and associated logic. */
    Player player;

    /** @brief Main enemy controller/instance. */
    Enemy enemy;
    std::vector<Enemy> enemies;

    /** @brief Background starfield system for parallax effects. */
    Stars stars;

    /** @brief Decorative background planets. */
    Planet planet;

    /** @brief Head-up Display (HUD) and menu elements. */
    UI ui;
};