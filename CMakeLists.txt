cmake_minimum_required(VERSION 3.21)
project(CSI_1430_Group_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


set(CMAKE_CXX_STANDARD_REQUIRED ON)

# macOS Homebrew support
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

# Find SDL2 libraries
find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_mixer REQUIRED CONFIG)

# Create executable
add_executable(CSI_1430_Group_Project
        SDL_Plotter.cpp
        SDL_Plotter.h
        Enemy.cpp
        Enemy.h
        Entity.cpp
        Entity.h
        Maze.cpp
        Maze.h
        maze1.txt
        test.cpp
        Tile.cpp
        Tile.h
        GameLoop.cpp
        Player.cpp
        Player.h
)

# Link SDL2 libraries
target_link_libraries(CSI_1430_Group_Project PRIVATE
        SDL2::SDL2
        SDL2::SDL2main
        SDL2_mixer::SDL2_mixer
)