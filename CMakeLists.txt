cmake_minimum_required(VERSION 3.10)
project(Asteroides)

# Add SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add your source files
add_executable(Asteroides
    src/main.cpp
    src/Game.cpp
    src/Game.hpp
    src/Ship.cpp 
    src/Ship.hpp
    src/Projectile.cpp 
    src/Projectile.hpp
    src/Asteroid.cpp
    src/Asteroid.hpp
)

# Link against SFML libraries
target_link_libraries(Asteroides PRIVATE sfml-graphics sfml-window sfml-system)
