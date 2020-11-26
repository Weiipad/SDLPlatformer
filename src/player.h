#pragma once

#include "node.h"
#include "my_math.h"

typedef struct Player
{
    Node super;
    Vec2 velocity;
} Player;

Player* Player_Create();