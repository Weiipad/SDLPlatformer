cmake_minimum_required(VERSION 3.13)

project(SDLPlatformer)

find_package(SDL2 REQUIRED)

add_executable(plat)

target_sources(plat
    PUBLIC
    src/sdl_header.h
    src/main_scene.h
    PRIVATE
    src/main.c
    src/scene.c
    src/game_state.c
    src/main_scene.c)

target_link_libraries(plat SDL2)