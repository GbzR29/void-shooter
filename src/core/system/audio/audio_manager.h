#pragma once

#include <unordered_map>
#include <vector>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

#include "../resource/resource_ids.h"

class ResourceManager;

/**
 * @class AudioManager
 * @brief Manages sound effects and music playback using a pooling system for efficiency.
 * * This class handles music tracks and a pool of sounds to avoid excessive memory allocation
 * and provides category-based volume control.
 */
class AudioManager {
public:
    /**
     * @brief Constructor for AudioManager.
     * @param rm Reference to the ResourceManager used to fetch audio assets.
     */
    AudioManager(ResourceManager& rm);

    /**
     * @brief Plays a music track by its ID.
     * @param id The unique identifier of the music resource.
     * @param loop Whether the music should restart automatically after finishing.
     */
    void playMusic(MusicID id, bool loop = true);

    /**
     * @brief Stops the currently playing music track and clears the pointer.
     */
    void stopMusic();

    /**
     * @brief Plays a sound effect using an available sound instance from the pool.
     * @param id The unique identifier of the sound buffer.
     * @param category The category (SFX, UI, etc.) used to determine volume levels.
     */
    void playSound(SoundID id, SoundCategory category);

    /**
     * @brief Updates the volume for a specific sound category.
     * @param category The category to modify.
     * @param volume The new volume level (typically 0.0 to 100.0).
     */
    void setVolume(SoundCategory category, float volume);

    /**
     * @brief Performs maintenance on the sound pool, removing stopped sounds.
     * @note This should be called once per frame in the main loop.
     */
    void update();

private:
    ResourceManager& rm;

    sf::Music* currentMusic = nullptr;

    /**
     * @struct SoundInstance
     * @brief Internal wrapper for an sf::Sound and its assigned category.
     */
    struct SoundInstance {
        sf::Sound sound;
        SoundCategory category;

        /**
         * @brief Constructs a new SoundInstance.
         * @param buffer The sound data buffer.
         * @param cat The category this sound belongs to.
         */
        SoundInstance(const sf::SoundBuffer& buffer, SoundCategory cat) : sound(buffer), category(cat) {}
    };

    std::vector<SoundInstance> soundPool;
    std::unordered_map<SoundCategory, float> volumes;
};