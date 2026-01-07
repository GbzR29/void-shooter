#include "resource_manager.h"
#include <iostream>

// ===== BINARIES =====
#include "../../assets/sprites/player/player_texture.h"
#include "../../assets/sprites/thruster/thruster_spritesheet.h"
#include "../../assets/sprites/enemy/purp_enemy_texture.h"
#include "../../assets/sprites/projectiles/laser_tex.h"
#include "../../assets/sprites/ui/healthbar_sprite.h"

#include "../../assets/sprites/planets/earth/earth_sprite.h"

#include "../../assets/audio/sfx/laser_shoot_sfx.h"
#include "../../assets/audio/bgm/starfighter_blitz_bgm.h"
#include "../../assets/audio/bgm/cosmic_assault_bgm.h"
#include "../../assets/fonts/pixel_font.h"

// ====================
// TEXTURES
// ====================
void ResourceManager::loadTexture(TextureID id)
{
    sf::Texture tex;

    switch (id) {
        case TextureID::Player:
            if (!tex.loadFromMemory(player_png, player_png_len)){
                std::cerr << "Failed tod load player texture" << std::endl;
            }       
            
            break;
        case TextureID::Thruster:
            if (!tex.loadFromMemory(thruster_png, thruster_png_len)){
                std::cerr << "Failed tod load thruster texture" << std::endl;
            }            
            break;
        case TextureID::Enemy:
            if (!tex.loadFromMemory(purple_enemy_png, purple_enemy_png_len)){
                std::cerr << "Failed tod load enemy texture" << std::endl;
            }
            break;
        case TextureID::Laser:
            if (!tex.loadFromMemory(laser_png, laser_png_len)){
                std::cerr << "Failed tod load laser texture" << std::endl;
            }
            break;
        case TextureID::HealthBar:
            if (!tex.loadFromMemory(healthbar_sprite_png, healthbar_sprite_png_len)){
                std::cerr << "Failed tod load healthbar texture" << std::endl;
            }            
            break;
        case TextureID::Planet:
            if(!tex.loadFromMemory(earth_sprite_png, earth_sprite_png_len)){
                std::cerr << "Failed tod load earth texture" << std::endl;
            }            
        break;
        default:
            std::cerr << "unknown TextureId\n";
            return;
    }

    textures.emplace(id, std::move(tex));
}

const sf::Texture& ResourceManager::getTexture(TextureID id)
{
    if (!textures.contains(id))
        loadTexture(id);

    return textures.at(id);
}

// ====================
// SOUNDS
// ====================
void ResourceManager::loadSound(SoundID id)
{
    sf::SoundBuffer buffer;

    switch (id) {
        case SoundID::LaserShot:
            if(!buffer.loadFromMemory(laser_shoot_ogg, laser_shoot_ogg_len)){
                std::cerr << "Failed to load laser_shot sfx" << std::endl;
            }            
            break;
        default:
            std::cerr << "unknown SoundID\n";
            return;
    }

    sounds.emplace(id, std::move(buffer));
}

const sf::SoundBuffer& ResourceManager::getSound(SoundID id)
{
    if (!sounds.contains(id))
        loadSound(id);

    return sounds.at(id);
}

// ====================
// MUSIC
// ====================
void ResourceManager::loadMusic(MusicID id)
{
    sf::Music music;

    switch (id) {
        case MusicID::Background:
            if (!music.openFromMemory(starfighter_blitz_mp3, starfighter_blitz_mp3_len)){
                std::cerr << "Failed to load background music" << std::endl;
            }
            break;
        default:
            std::cerr << "unknown MusicID\n";
            return;
    }

    musics.emplace(id, std::move(music));
}

sf::Music& ResourceManager::getMusic(MusicID id)
{
    if (!musics.contains(id))
        loadMusic(id);

    return musics.at(id);
}

// ====================
// FONTS
// ====================
void ResourceManager::loadFont(FontID id)
{
    sf::Font font;

    switch (id) {
        case FontID::Pixel:
            if (!font.openFromMemory(pixel_font_ttf, pixel_font_ttf_len))
            {
                std::cerr << "Failed to load pixel font" << std::endl;
            }
            break;
        default:
            std::cerr << "unknown FontID\n";
            return;
    }

    fonts.emplace(id, std::move(font));
}

const sf::Font& ResourceManager::getFont(FontID id)
{
    if (!fonts.contains(id))
        loadFont(id);

    return fonts.at(id);
}
