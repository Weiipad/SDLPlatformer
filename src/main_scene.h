#pragma once

#include "scene.h"
#include "node.h"
#include "player.h"

typedef struct MainScene 
{
    Scene super;
    Node* root;
    Player* player;
} MainScene;

Scene* MainScene_Create();