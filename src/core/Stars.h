#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Stars {
public:
    Stars(std::size_t count = 150) {
        create_stars(count);
    }

    void draw_stars(sf::RenderWindow& window) {
        for (const auto& star : stars) {
            window.draw(star);
   
        }
    }

    void update_stars(float delta_time) {
        for (auto& star : stars) {
            star.move({0.f, 100.f * delta_time}); //vertical speed

            if (star.getPosition().y > 600.f) {
                float newX = distribX(gen);
                star.setPosition({newX, 0.f});
            }
        }
    }

private:

    //generating a random value for X and Y axis with Mersenne Twister
    std::random_device rd;
    std::mt19937 gen{ rd() };

    std::uniform_real_distribution<float> distribX{ 0.f, 800.f };
    std::uniform_real_distribution<float> distribY{ 0.f, 600.f };

    std::vector<sf::CircleShape> stars;

    void create_stars(std::size_t count) {

        //define a value for the size of the vector
        stars.reserve(count);

        for (std::size_t i = 0; i < count; ++i) {
            sf::CircleShape star{ 0.5f };

            star.setScale({ std::uniform_real_distribution<float>(0.5f, 2.0f)(gen), std::uniform_real_distribution<float>(0.5f, 2.0f)(gen) });
            star.setFillColor(sf::Color::White);
            star.setPosition({distribX(gen), distribY(gen)});

            stars.push_back(star);
        }
    }
};
