#include "audio_manager.h"

#include "../resource/resource_manager.h"
#include "../resource/resource_ids.h"

#include <algorithm>

AudioManager::AudioManager(ResourceManager& rm) : rm(rm){
    volumes[SoundCategory::Music] = 10.f;
    volumes[SoundCategory::SFX]   = 40.f;
    volumes[SoundCategory::UI]    = 50.f;
    
    // reserve space to avoid frequent relocations.
    soundPool.reserve(32);
}

void AudioManager::playSound(SoundID id, SoundCategory category) {
    // trying to reuse a still sound
    for (auto& s : soundPool) {
        if (s.sound.getStatus() == sf::Sound::Status::Stopped) {
            s.sound.setBuffer(rm.getSound(id));
            s.sound.setVolume(volumes[category]);
            s.sound.play();
            s.category = category;
            return;
        }
    }

    // if no sound is available, create a new one.
    soundPool.emplace_back(rm.getSound(id), category);
    
    // adjust the volume and press play on the new sound.
    SoundInstance& instance = soundPool.back();
    instance.sound.setVolume(volumes[category]);
    instance.sound.play();
}

void AudioManager::playMusic(MusicID id, bool loop) {
    if (currentMusic) {
        currentMusic->stop();
    }

    currentMusic = &rm.getMusic(id);
    currentMusic->setLooping(loop);
    currentMusic->setVolume(volumes[SoundCategory::Music]);
    currentMusic->play();
}

void AudioManager::stopMusic() {
    if (currentMusic) {
        currentMusic->stop();
        currentMusic = nullptr;
    }
}

void AudioManager::update() {
    soundPool.erase(std::remove_if(soundPool.begin(), soundPool.end(), [](const SoundInstance& s)
    {
        return s.sound.getStatus() == sf::Sound::Status::Stopped;
    }), soundPool.end());
}
