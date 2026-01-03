#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Stars.h"
#include <iostream>
#include <cmath>

#include "../assets/textures/earth_texture_spritesheet.h"
#include "../assets/textures/earth_spritesheet.h"
#include "../assets/textures/purp_enemy_texture.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    // window
    sf::Clock clock;
    float elapse_time = 0;
    float frame_duration;
    int frames = 0;    

    //Entities
    Player player;
    Stars stars;        
  
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

    // =================================================================================================    
    
    //enemy texture & attributes =======================================================================
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromMemory(purple_enemy_png, purple_enemy_png_len))
    {
        std::cout << "Failed to load purple_enemy texture" << std::endl;
    } 
    sf::Sprite purple_enemy_sprite(enemyTexture);   

    float enemy_x_position = 400.f - 25.f;
    float enemy_y_position = 10;
    float amplitude = 150.0f;   

    float enemy_anim_time = 0;       

    purple_enemy_sprite.setScale({3.f, 3.f});
    purple_enemy_sprite.setPosition({ enemy_x_position, enemy_y_position });

    while (window.isOpen())
    {               
        float delta_time = clock.restart().asSeconds();     
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

        //enemy animation
        enemy_anim_time += delta_time;       
        float x = enemy_x_position + std::sin(enemy_anim_time * 2.f) * amplitude;
        float y = enemy_y_position + std::cos(enemy_anim_time * 2.f) * amplitude;     
        
        //setting bounds for enemy translation in Y
        enemy_y_position <= 600 ? enemy_y_position += 100 * delta_time : enemy_y_position = -50;

        purple_enemy_sprite.setPosition({x, enemy_y_position});         
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        stars.draw_stars(window);
        stars.update_stars(delta_time);

        window.draw(earth_sprite);


        window.draw(purple_enemy_sprite);

        player.update(delta_time);        
        player.draw(window);        

        window.display();
    }


    return 0;
}