#include "ui.h"

#include <iostream>

UI::UI(ResourceManager& rm) : healthbar_sprite(rm.getTexture(TextureID::HealthBar)), score_text(rm.getFont(FontID::Pixel)){
    
    score_text = sf::Text(rm.getFont(FontID::Pixel));
    score_text.setString("Score: ");
    score_text.setCharacterSize(32);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition({650, 5});

    healthbar_sprite = sf::Sprite(rm.getTexture(TextureID::HealthBar));
    healthbar_sprite.setScale({2, 2});
    healthbar_sprite.setPosition({10, 10});
    healthbar_sprite.setTextureRect(sf::IntRect({0, 0},{100, 16}));
}

void UI::draw(sf::RenderWindow &window){
    window.draw(healthbar_sprite);
    window.draw(score_text);
}

