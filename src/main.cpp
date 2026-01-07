#include <SFML/Graphics.hpp>

#include "game/game.h"

#include <iostream>

int main() {
    // instantiates the window system.
    WindowManager window(1200, 900, "Void Shooter");
    window.setupSettings(120, true, false);

    // instantiates the resources
    ResourceManager rm;
    AudioManager audio(rm);

    // set up the context (pointer package)
    GameContext ctx{ &window, &rm, &audio };

    // start the game
    Game game(ctx);
    game.run();

    return 0;
}