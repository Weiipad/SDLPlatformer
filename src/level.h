#pragma once

#include "sdl_header.h"
#include "node.h"
#include "array_list.h"

typedef struct Level
{
    Node node;
    ArrayList tiles;
    SDL_Surface* level_map;

    // width and height in tiles
    int witdth;
    int height;
} Level;

int Level_Collides(Level* self, const Rect* collider, Rect* outWhich);

void Level_Reload(SDL_Surface* new_level_map);

Level* Level_Create(SDL_Surface* level_map);