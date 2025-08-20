cmake_minimum_required(VERSION 3.10)
project(Asteroides)

# Add SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Asteroides ${SOURCES})

# Link against SFML libraries
target_link_libraries(Asteroides PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(Asteroides PRIVATE ${PROJECT_SOURCE_DIR}/src)

if (WIN32)
    target_link_libraries(Asteroides PRIVATE sfml-main)
    set_target_properties(Asteroides PROPERTIES WIN32_EXECUTABLE ON)
endif()