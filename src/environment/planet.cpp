#include "planet.h"

#include "../core/system/resource/resource_manager.h"

Planet::Planet(GameContext& ctx) : earth_sprite(ctx.resources->getTexture(TextureID::Planet)){
    
    this->ctx = &ctx;

    earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame, 0}, {100, 100}));
    earth_sprite.setScale({10.0f, 10.0f});
    earth_sprite.setPosition({-150, 600});
    earth_sprite.setColor(sf::Color(100, 100, 100, 255));
}

void Planet::update(float dt){
    //earth animation
    float earth_time_scale = 0.05;
    earth_anim_time += dt * earth_time_scale;

    const float earth_fps = 120.f;
    earth_actual_frame = static_cast<int>(earth_anim_time * earth_fps) % earth_total_frames;

    earth_sprite.setTextureRect(sf::IntRect({earth_actual_frame * 100, 0}, {100, 100}));
}

void Planet::draw(sf::RenderWindow& window){
    window.draw(earth_sprite);
}