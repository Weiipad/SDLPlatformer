#pragma once

#include "node.h"
#include "my_math.h"

#include "level.h"

typedef struct Player
{
    Node super;
    Vec2 size;
    Vec2 velocity;

    int jumpDown;

    Level* current_level;
} Player;

Player* Player_Create(Level* current_level, Vec2 start, Vec2 size);