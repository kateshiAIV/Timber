# Timber

Timber is an arcade-style, fast-paced tree-chopping game built with C++ and SFML 3.x. Swing your axe, avoid obstacles, collect power-ups, and see how long you can survive!

- Repository description: Timber game developed with SFML 3.0.1
- Languages: C++, CMake

---

## Table of contents

- [Screenshots](#screenshots)
- [Features](#features)
- [Controls](#controls)
- [Build & Run](#build--run)
- [Dependencies](#dependencies)
- [Packaging / Distribution](#packaging--distribution)

---

## Screenshots
![Gameplay Screenshot](https://github.com/user-attachments/assets/18134e9d-9ee0-4bb2-b1a6-957eb748fb0f)
![Gameplay Screenshot 2](https://github.com/user-attachments/assets/1fc5b6a1-3ed3-4ef0-b566-8b0036631900)


## Features

- Arcade-style tree-chopping gameplay
- Smooth 60+ FPS rendering with SFML 3.x
- Keyboard (and optional controller) input
- Simple, configurable scoring system
- Sound effects and music (SFML Audio)
- Configurable difficulty and power-ups
- Cross-platform: Windows, macOS, Linux (via CMake)

---

## Controls

Default controls (configurable in code)
- Left player / chop left: Left Arrow (or A)
- Right player / chop right: Right Arrow (or D)
- Pause: P or Esc
- Restart after game over: R

(If your build supports controllers, include controller mappings in the game options.)

---

## Build & Run

This project uses CMake. The repository is setup to use FetchContent to obtain SFML automatically, but you can also install SFML system-wide and let CMake find it.

Basic build steps (from project root):

Unix / macOS / Windows (with multi-config generators, add `--config Release` to the build step):

```bash
# Create a build directory and configure
cmake -B build -S .

# Build the project
cmake --build build --config Release

# Run the game (binary name may vary; replace `timber` with your executable)
./build/timber
# or on Windows:
.\build\Release\timber.exe
```

Notes
- To change compilers or generator, pass `-G` or set `CMAKE_CXX_COMPILER`.
- To change build type for single-config generators, pass `-DCMAKE_BUILD_TYPE=Release` (or Debug).

Troubleshooting
- If SFML is not downloaded or configured, check CMake output for errors. You can also set `SFML_DIR` to a local SFML build.
- On Linux, if you prefer using the system SFML package, install SFML and remove or modify the FetchContent section in `CMakeLists.txt`.

---

## Dependencies

- CMake (>= 3.19 recommended)
- C++17 or later (configured in CMake)
- SFML 3.x (the template uses FetchContent to download SFML; repository description indicates SFML 3.0.1)

Linux packages (Ubuntu/Debian) for building SFML from system packages (if you choose not to use FetchContent):
```bash
sudo apt update
sudo apt install libxrandr-dev libxcursor-dev libxi-dev libudev-dev libfreetype-dev \
                 libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev
```

---

## Packaging / Distribution

- Windows: create an installer or bundle the executable with required DLLs (SFML dynamic libs) or build static.
- macOS: create a .app bundle (embed SFML frameworks).
- Linux: provide a tarball with executable and any required shared libraries, or build a distro package.

To build a static executable, modify your CMake options to link SFML statically and set the appropriate compile/link flags. Check `CMakeLists.txt` for `SFML_USE_STATIC_LIBS` or GIT_TAG options for FetchContent.
