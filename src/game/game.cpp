#include "game.h"
#include <algorithm>

/**
 * @details Initializes all game objects by passing the GameContext. 
 * The stars are initialized with a fixed count of 300 for the background effect.
 */
Game::Game(GameContext& ctx) : ctx(ctx), player(ctx), enemy(ctx), stars(ctx, 300), planet(ctx), ui(ctx) {}

void Game::run() {
    // Start background music loop immediately on game start
    ctx.audio->playMusic(MusicID::Background, true);

    sf::Clock clock;

    enemies.reserve(10);

    for (int i = 0; i < 10; i++)
    {
        enemies.emplace_back(ctx);
    }

    enemies.at(1).set_enemyPosition({500, 100});

    for (auto& proj : player.getAmmunition()) {
        if (!proj.isActive()) continue;

    // Check against each enemy
    for (auto& e : enemies) {
        if (!e.isAlive()) continue;

        // Check the intersection of FloatRect
        if (proj.collision_box.findIntersection(e.collision_box)) {
            proj.onCollision(e); // O projétil "avisa" que colidiu com essa entidade
            break; // Stop checking this projectile for this frame.
        }
    }
}

    /**
     * Main Game Loop
     * @see https://www.sfml-dev.org/tutorials/3.0/window/events/
     */
    while (ctx.window->isOpen()) {
        sf::Time dtTime = clock.restart();
        
        // Delta Time Clamping: Prevents huge jumps in physics if the window is moved or lags
        float dt = std::min(dtTime.asSeconds(), 0.05f);

        // 1. Event Polling Phase
        while (const std::optional event = ctx.window->window().pollEvent()) {   
            if (event->is<sf::Event::Closed>())
                ctx.window->window().close();

            // Delegate event handling to the player entity
            player.handleEvent(*event, dt); 
        }
        
        // 2. Update Phase: Physics, AI, and Animations
        stars.update(dt);
        planet.update(dt);
        player.update(dt);
        enemies.at(0).update(dt);
        enemies.at(1).update(dt);
        // ctx.audio->update(dtTime); // Future implementation for audio maintenance

        // 3. Draw Phase: Rendering all layers
        sf::RenderWindow& rw = ctx.window->window();
        
        rw.clear(); 
        
        // Rendering order matters (Back to Front)
        stars.draw(rw);             // Background layer 1
        planet.draw(rw);            // Background layer 2

        player.draw(rw);            // Gameplay layer
        enemies.at(0).draw(rw);     // Gameplay layer
        enemies.at(1).draw(rw);     // Gameplay layer

        ui.draw(rw);                // UI/Overlay layer
        
        rw.display();
    }
}