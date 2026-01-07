#include "ui.h"

#include <iostream>

UI::UI(GameContext &ctx) : healthbar_sprite(ctx.resources->getTexture(TextureID::HealthBar)), score_text(ctx.resources->getFont(FontID::Pixel)){
    
    score_text.setString("Score: ");
    score_text.setCharacterSize(32);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition({650, 5});

    healthbar_sprite = sf::Sprite(ctx.resources->getTexture(TextureID::HealthBar));
    healthbar_sprite.setScale({2, 2});
    healthbar_sprite.setPosition({10, 10});
    healthbar_sprite.setTextureRect(sf::IntRect({0, 0},{100, 16}));
}

void UI::draw(sf::RenderWindow &window){
    window.draw(healthbar_sprite);
    window.draw(score_text);
}

