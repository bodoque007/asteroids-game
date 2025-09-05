cmake_minimum_required(VERSION 3.10)
project(Asteroides)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.1
)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(sfml)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(Asteroides ${SRC_FILES})

target_link_libraries(Asteroides PRIVATE sfml-graphics sfml-window sfml-system)

include(GNUInstallDirs)

install(TARGETS Asteroides
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(IMPORTED_RUNTIME_ARTIFACTS sfml-graphics sfml-window sfml-system
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
