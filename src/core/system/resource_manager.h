#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

#include "resource_ids.h"

class ResourceManager {
public:
    // textures
    const sf::Texture& getTexture(TextureID id);

    // sounds
    const sf::SoundBuffer& getSound(SoundID id);

    // musics
    sf::Music& getMusic(MusicID id);

    // fonts
    const sf::Font& getFont(FontID id);

private:
    // internal loaders
    void loadTexture(TextureID id);
    void loadSound(SoundID id);
    void loadMusic(MusicID id);
    void loadFont(FontID id);

    std::unordered_map<TextureID, sf::Texture> textures;
    std::unordered_map<SoundID, sf::SoundBuffer> sounds;
    std::unordered_map<MusicID, sf::Music> musics;
    std::unordered_map<FontID, sf::Font> fonts;
};
