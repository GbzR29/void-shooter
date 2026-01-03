#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Stars.h"
#include <iostream>
#include <cmath>

#include "../assets/textures/earth_texture_spritesheet.h"
#include "../assets/textures/purp_enemy_texture.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    //Entities
    Player player;
    Stars stars;

    //Sin function
    sf::Clock animation_clock;

    float xPos = 400.f - 25.f;
    float yPos = 150;
    float amplitude = 150.0f;    
  
    // earth texture =======================================================================
    sf::Texture earth_texture;
    if (!earth_texture.loadFromMemory(earth_texture_png, earth_texture_png_len))
    {
        std::cout << "Failed to load earth texture" << std::endl;
    }
    sf::Sprite earth_sprite(earth_texture);    

    int total_frames = 50;
    int actual_frame = 0;
    int counter = 0;

    earth_sprite.setTextureRect(sf::IntRect({actual_frame, 0}, {100, 100}));
    earth_sprite.setScale({3.0f, 3.0f});
    earth_sprite.setPosition({100, 100});
    earth_sprite.setColor(sf::Color(80, 80, 80, 255));

    // ======================================================================================

    // window
    sf::Clock clock;
    float elapse_time = 0;
    float frame_duration;
    int frames = 0;    
    
    //enemy texture =======================================================================
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromMemory(purple_enemy_png, purple_enemy_png_len))
    {
        std::cout << "Failed to load purple_enemy texture" << std::endl;
    }    
    sf::Sprite purple_enemy_sprite(enemyTexture);

    purple_enemy_sprite.setScale({3.f, 3.f});
    purple_enemy_sprite.setPosition({ 400 - 25.f, 0.f });

    float earth_anim_time = 0;

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



        counter == 20 ? actual_frame = (actual_frame + 100) % 10000, counter = 0 : counter++;          
        earth_sprite.setTextureRect(sf::IntRect({actual_frame, 0}, {100, 100}));


        //enemy animation
        earth_anim_time += delta_time;       
        float x = xPos + std::sin(earth_anim_time * 2.f) * amplitude;
        float y = yPos + std::cos(earth_anim_time * 2.f) * amplitude;     
        
        //setting bounds for enemy translation in Y
        yPos <= 600 ? yPos += 100 * delta_time : yPos = -50;

        purple_enemy_sprite.setPosition({x, yPos});         
        

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