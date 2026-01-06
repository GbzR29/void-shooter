#include "audio-manager.h"
#include "../../assets/audio/bgm/CosmicAssault_bgm.h"
#include "../../assets/audio/bgm/StarfighterBlitz_bgm.h"

bool AudioManager::playBackgroundMusic(bool loop) {

    if (!music.openFromMemory(StarfighterBlitz_mp3, StarfighterBlitz_mp3_len)) {
        std::cerr << "Error loading music file: " << std::endl;
        return false;
    } 

    music.setLooping(loop);
    music.setVolume(50.f); // Initial volume in 50%
    music.play();
    return true;
}

void AudioManager::setVolume(float volume) {
    music.setVolume(volume);
}

void AudioManager::stopMusic() {
    music.stop();
}