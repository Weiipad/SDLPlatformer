#pragma once

#include "node.h"
#include <SDL2/SDL.h>

typedef struct Sprite
{
    Node super;
    SDL_Texture* texture;
    Vec2 size;
} Sprite;

Node* Sprite_Create(SDL_Texture* texture, Vec2 size);