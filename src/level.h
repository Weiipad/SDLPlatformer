#pragma once

#include "sdl_header.h"
#include "node.h"
#include "array_list.h"

typedef struct Level
{
    Node node;
    ArrayList tiles;
} Level;

int Level_Collides(Level* self, const Rect* collider);

Level* Level_Create(SDL_Surface* level);