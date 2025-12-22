#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Void Shooter");

    //Entities
    Player player;

    //Delta time
    sf::Clock clock;

    //Sin function
    sf::Clock timeClock;

    float delta_time = 0;

    float baseX = 400.f - 25.f;
    float baseY = 150;
    float amplitude = 150.0f;

    float yPos = 0;
    float xPos = 0;
  
    sf::Texture enemyTexture("assets/textures/purple.png");
    sf::Sprite rect(enemyTexture);
    rect.setScale({3.f, 3.f});

    rect.setPosition({ 400 - 25.f, 0.f });

    while (window.isOpen())
    {
        delta_time = clock.restart().asSeconds();

        float t = timeClock.getElapsedTime().asSeconds();
        //std::cout << t << std::endl;

        float x = baseX + std::sin(t * 2.f) * amplitude;
        float y = baseY + std::cos(t * 2.f) * amplitude;

        rect.setPosition({ x, y });   

        //setting bounds for enemy translation in Y
        if (yPos > 600)
        {
            yPos = -50;
        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        window.draw(rect);

        player.update(delta_time);        
        player.draw(window);        

        window.display();
    }
}