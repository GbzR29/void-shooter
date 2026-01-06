#include "ui.h"
#include "../../assets/textures/healthbar_spritesheet.h"
#include "../../assets/textures/energybar_spritesheet.h"
#include "../../assets/fonts/PixelifySansRegular.h"

#include <iostream>

UI::UI() : healthbar_sprite(healthbar_texture), score_text(default_font){
    
    if(!healthbar_texture.loadFromMemory(healthbar_spritesheet_png, healthbar_spritesheet_png_len)){
        std::cout << "Failed to load healthbar texture" << std::endl;
    }

    //Score Text
    if (!default_font.openFromMemory(PixelifySans_Regular_ttf, PixelifySans_Regular_ttf_len))
    {
        std::cout << "Failed to load PixelifySans-Regular font" << std::endl;
    }

    score_text = sf::Text(default_font);
    score_text.setString("Score: ");
    score_text.setCharacterSize(32);
    score_text.setFillColor(sf::Color::White);
    score_text.setPosition({650, 5});

    healthbar_sprite = sf::Sprite(healthbar_texture);
    healthbar_sprite.setScale({2, 2});
    healthbar_sprite.setPosition({10, 10});
    healthbar_sprite.setTextureRect(sf::IntRect({0, 0},{100, 16}));

}

void UI::draw(sf::RenderWindow &window){
    window.draw(healthbar_sprite);
    window.draw(score_text);
}

