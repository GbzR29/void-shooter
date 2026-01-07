#include <SFML/Graphics.hpp>

#include "entities/player/player.h"
#include "entities/enemy/enemy.h"
#include "environment/stars.h"
#include "environment/planet.h"

#include "sound/audio-manager.h"

#include "ui/ui.h"

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    // window
    sf::Clock clock;
    float elapse_time = 0;
    float frame_duration;
    int frames = 0;    

    // resources
    ResourceManager rm;

    // entities
    Player player(rm);
    Enemy enemy(rm);

    // environment
    Stars stars(150);    
    Planet planet(rm);

    // ui
    UI ui(rm);

    // audio
    AudioManager audio(rm);    
         
    float delta_time = 0;

    //game loop
    while (window.isOpen())
    {               
        delta_time = clock.restart().asSeconds();     
        // delta time clamping
        delta_time = std::min((double)delta_time, 0.05);

        //show fps in window title
        elapse_time += delta_time;
        frames++;
        int fps = frames / elapse_time;
        window.setTitle("Void Shooter - FPS: " + std::to_string(fps));    
              
        //event loop
        while (const std::optional event = window.pollEvent())
        {   
            player.handleEvent(*event, delta_time);

            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        // environment draw
        stars.draw_stars(window);
        planet.draw(window);

        // environment update
        stars.update_stars(delta_time);
        planet.update(delta_time);

        // entities draw        
        player.draw(window);
        enemy.draw(window);

        // entities update
        player.update(delta_time); 
        enemy.update(delta_time);
        
        // ui draw
        ui.draw(window);

        window.display();
    }

    return 0;
}