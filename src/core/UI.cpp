#include "../headers/UI.h"
#include "../assets/textures/healthbar_spritesheet.h"
#include "../assets/textures/energybar_spritesheet.h"
#include <iostream>

UI::UI() : healthbar_sprite(healthbar_texture) {

    if(!healthbar_texture.loadFromMemory(healthbar_spritesheet_png, healthbar_spritesheet_png_len)){
        std::cout << "Failed to load healthbar texture" << std::endl;
    }

    healthbar_sprite = sf::Sprite(healthbar_texture);
    healthbar_sprite.setScale({2, 2});
    healthbar_sprite.setPosition({10, 10});
    healthbar_sprite.setTextureRect(sf::IntRect({0, 0},{100, 16}));

}

void UI::draw(sf::RenderWindow &window){
    window.draw(healthbar_sprite);
}

