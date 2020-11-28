#pragma once

#include "scene.h"
#include "node.h"
#include "player.h"
#include "level.h"

typedef struct MainScene 
{
    Scene super;
    Node* root;
    Player* player;
    Level* level;

    Vec2 camera_position;
} MainScene;

Scene* MainScene_Create();