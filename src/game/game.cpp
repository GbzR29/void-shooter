#include "game.h"

#include <algorithm>

Game::Game(GameContext& ctx) : ctx(ctx), player(ctx), enemy(ctx), stars(ctx, 300), planet(ctx), ui(ctx) {}

void Game::run() {

    // background music
    ctx.audio->playMusic(MusicID::Background, true);

    sf::Clock clock;

    // game loop
    while (ctx.window->isOpen()) {
        sf::Time dtTime = clock.restart();
        float dt = std::min(dtTime.asSeconds(), 0.05f);

        // processing everything, systems and player input
        while (const std::optional event = ctx.window->window().pollEvent()) {   
            if (event->is<sf::Event::Closed>())
                ctx.window->window().close();

            // the player receives the unreferenced event.
            player.handleEvent(*event, dt); 
        }
        
        // update
        stars.update(dt);
        planet.update(dt);
        player.update(dt);
        enemy.update(dt);
        //ctx.audio->update(dtTime);

        // draw
        // Using the internal window reference
        sf::RenderWindow& rw = ctx.window->window();
        
        rw.clear(); 
        stars.draw(rw);
        planet.draw(rw);
        player.draw(rw);
        enemy.draw(rw);
        ui.draw(rw);
        rw.display();
    }
}
