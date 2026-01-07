#pragma once

#include "system/audio/audio_manager.h"
#include "system/resource/resource_manager.h"
#include "system/window/window_manager.h"

struct GameContext {
    WindowManager* window = nullptr;
    ResourceManager* resources = nullptr;
    AudioManager* audio = nullptr;
};