## Overview

A simple Asteroids game (not fully implemented yet) implemented in C++ using the SFML library.  
Made mostly to learn a little bit about game programming and how to make C++ code run cross-platform.

![Gameplay screenshot](https://github.com/user-attachments/assets/f43beabd-7945-43a5-9554-24c7ba1e53a2)

---

## Getting Started

### Prerequisites

Before you begin, make sure you have the following dependencies installed:

- [CMake](https://cmake.org/download/)
- [SFML](https://www.sfml-dev.org/download.php)
- A C++ compiler:
  - **Linux:** GCC / Clang
  - **Windows:** MinGW-w64 or MSVC

---

bash
bash
bash

### Building on Linux

1. Clone the repository and build:

```bash
git clone https://github.com/bodoque007/Asteroids.git
cd Asteroids
mkdir build
cd build
cmake ..
cmake --build .
./Asteroides
```

---

### Building on Windows (MinGW)

1. Clone the repository and build:

```cmd
git clone https://github.com/bodoque007/Asteroids.git
cd Asteroids
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build . --config Release
Asteroides.exe
```

> **Note:** Make sure the SFML `.dll` files are in the same folder as the executable, otherwise the game will fail to launch.
