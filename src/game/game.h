#pragma once

#include "../core/game_context.h"

#include "../entities/player/player.h"
#include "../entities/enemy/enemy.h"

#include "../environment/stars.h"
#include "../environment/planet.h"

#include "../ui/ui.h"

class Game {
public:
    Game(GameContext& ctx);
    void run();

private:
    GameContext& ctx;

    Player player;
    Enemy enemy;
    Stars stars;
    Planet planet;
    UI ui;
};
