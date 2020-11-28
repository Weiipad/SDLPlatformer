#pragma once

#include "sdl_header.h"
#include "node.h"
#include "array_list.h"

typedef struct Level
{
    Node node;
    ArrayList tiles;
} Level;

Level* Level_Create(SDL_Surface* level);