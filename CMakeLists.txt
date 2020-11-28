cmake_minimum_required(VERSION 3.13)

project(SDLPlatformer)

find_package(SDL2 REQUIRED)

add_executable(plat)

target_sources(plat
PUBLIC    
    src/sdl_header.h
    src/scene.h
    src/main_scene.h
    src/node.h
    src/game_state.h
    src/my_math.h
    src/sprite.h
    src/rect_shape.h
    src/level.h
    src/player.h
    src/array_list.h
    src/color.h
PRIVATE
    src/main.c
    src/scene.c
    src/main_scene.c
    src/node.c
    src/game_state.c
    src/my_math.c
    src/sprite.c
    src/rect_shape.c
    src/level.c
    src/player.c
    src/array_list.c
    src/color.c
)

target_link_libraries(plat SDL2)