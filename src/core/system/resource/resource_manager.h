#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

#include "resource_ids.h"

/**
 * @file resource_manager.h
 * @brief Centralized manager responsible for loading and caching game resources.
 *
 * Implements lazy loading for textures, sounds, music and fonts,
 * ensuring that each resource is loaded only once and reused
 * throughout the application lifetime.
 */
class ResourceManager {
public:
    /**
     * @brief Retrieves a texture resource.
     *
     * Loads the texture on first request and caches it for future use.
     *
     * @param id Identifier of the texture resource.
     * @return Constant reference to the requested texture.
     */
    const sf::Texture& getTexture(TextureID id);

    /**
     * @brief Retrieves a sound buffer resource.
     *
     * Loads the sound buffer on first request and caches it.
     *
     * @param id Identifier of the sound resource.
     * @return Constant reference to the requested sound buffer.
     */
    const sf::SoundBuffer& getSound(SoundID id);

    /**
     * @brief Retrieves a music stream resource.
     *
     * Music is loaded and kept alive by the resource manager.
     *
     * @param id Identifier of the music resource.
     * @return Reference to the requested music object.
     */
    sf::Music& getMusic(MusicID id);

    /**
     * @brief Retrieves a font resource.
     *
     * Loads the font on first request and caches it.
     *
     * @param id Identifier of the font resource.
     * @return Constant reference to the requested font.
     */
    const sf::Font& getFont(FontID id);

private:
    /**
     * @brief Loads a texture resource into memory.
     *
     * Internal method called automatically when a texture
     * is requested for the first time.
     */
    void loadTexture(TextureID id);

    /**
     * @brief Loads a sound buffer resource into memory.
     */
    void loadSound(SoundID id);

    /**
     * @brief Loads a music resource into memory.
     */
    void loadMusic(MusicID id);

    /**
     * @brief Loads a font resource into memory.
     */
    void loadFont(FontID id);

private:
    std::unordered_map<TextureID, sf::Texture> textures;
    std::unordered_map<SoundID, sf::SoundBuffer> sounds;
    std::unordered_map<MusicID, sf::Music> musics;
    std::unordered_map<FontID, sf::Font> fonts;
};
