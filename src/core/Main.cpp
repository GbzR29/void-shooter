#include <SFML/Graphics.hpp>

#include "entities/player/player.h"
#include "entities/enemy/enemy.h"
#include "environment/stars.h"

#include "sound/audio-manager.h"

#include "ui/ui.h"

#include <iostream>

#include "../assets/textures/earth_texture_spritesheet.h"
#include "../assets/textures/earth_spritesheet.h"

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

    //Entities
    Player player;
    Enemy enemy;
    Stars stars(150);      
    
    UI ui;
    AudioManager audio;

    audio.playBackgroundMusic(true);
      
    // earth texture =======================================================================
    sf::Texture earth_texture;
    if (!earth_texture.loadFromMemory(earth_spritesheet_png, earth_spritesheet_png_len))
    {
        std::cout << "Failed to load earth texture" << std::endl;
    }
    sf::Sprite earth_sprite(earth_texture); 

    float earth_anim_time = 0.f;    
    const int earth_total_frames = 163;
    int earth_actual_frame = 0;

    earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame, 0}, {100, 100}));
    earth_sprite.setScale({10.0f, 10.0f});
    earth_sprite.setPosition({-100, 400});
    earth_sprite.setColor(sf::Color(100, 100, 100, 255));
   
    float delta_time = 0;

    while (window.isOpen())
    {               
        delta_time = clock.restart().asSeconds();     
        //delta time clamping
        delta_time = std::min((double)delta_time, 0.05);

        elapse_time += delta_time;
        frames++;
        int fps = frames / elapse_time;

        window.setTitle("Void Shooter - FPS: " + std::to_string(fps));    
        
        //earth animation
        float earth_time_scale = 0.05;
        earth_anim_time += delta_time * earth_time_scale;

        const float earth_fps = 120.f;
        earth_actual_frame = static_cast<int>(earth_anim_time * earth_fps) % earth_total_frames;

        earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame * 100, 0}, {100, 100}));
              
        
        while (const std::optional event = window.pollEvent())
        {   
            player.handleEvent(*event, delta_time);

            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        stars.draw_stars(window);
        stars.update_stars(delta_time);

        window.draw(earth_sprite);

        enemy.update(delta_time);
        enemy.draw(window);

        player.update(delta_time);        
        player.draw(window);
        
        ui.draw(window);

        window.display();
    }

    return 0;
}