#include "stars.h"

Stars::Stars(GameContext& ctx, std::size_t count){
    this->ctx = &ctx;
    create_stars(count);
}

void Stars::draw(sf::RenderWindow& window) {
    for (const auto& star : stars) {
        window.draw(star);   
    }
}

void Stars::update(float delta_time) {
    for (auto& star : stars) {
        star.move({0.f, 100.f * delta_time}); //vertical speed

        if (star.getPosition().y > 900.f) {
            float newX = distribX(gen);
            star.setPosition({newX, 0.f});
        }
    }
}

void Stars::create_stars(std::size_t count) {

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