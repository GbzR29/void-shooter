#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Stars {   

    private:

        //generating a random value for X and Y axis with Mersenne Twister
        std::random_device rd;
        std::mt19937 gen{ rd() };

        std::uniform_real_distribution<float> distribX{ 0.f, 800.f };
        std::uniform_real_distribution<float> distribY{ 0.f, 600.f };

        std::vector<sf::CircleShape> stars;
        void create_stars(std::size_t count);

    public:
        Stars(std::size_t count);
        void draw_stars(sf::RenderWindow& window);
        void update_stars(float delta_time);
};
