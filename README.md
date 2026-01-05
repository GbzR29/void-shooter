# Void Shooter

Void Shooter is a small 2D space shooter made in **C++ with SFML**.  
This project was built mainly for learning, testing ideas, and having fun with low-level game code.

You control a ship drifting through empty space. Move, shoot, and try to stay alive.

---

## Controls

- **W A S D** — Move
- **Space** — Shoot

---

## Install / Run

### Play the game

To test the game, run the executable located in: build/release/void-shooter.exe

---

### Build from source

If you want to compile the code yourself, use the CMake commands below.

#### Debug 🐞

```bash
cmake -S . -B build/debug -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug
```

#### Release 🚀

```bash
cmake -S . -B build/release -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build/release
```
