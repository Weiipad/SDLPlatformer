#pragma once

#include "node.h"
#include "my_math.h"

typedef struct Player
{
    Node super;
    Rect collider;
    Vec2 velocity;
} Player;

Player* Player_Create(Vec2 start, Vec2 size);