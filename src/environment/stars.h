#pragma once

#include "../core/game_context.h"

#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

class Stars {   

    private:

        GameContext* ctx;

        //generating a random value for X and Y axis with Mersenne Twister
        std::random_device rd;
        std::mt19937 gen{ rd() };

        std::uniform_real_distribution<float> distribX{ 0.f, 1200.f };
        std::uniform_real_distribution<float> distribY{ 0.f, 900.f };

        std::vector<sf::CircleShape> stars;
        void create_stars(std::size_t count);

    public:
        Stars(GameContext& ctx,std::size_t count);
        void draw(sf::RenderWindow& window);
        void update(float delta_time);
};
