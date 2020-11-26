#pragma once

#include "scene.h"
#include "node.h"

typedef struct MainScene 
{
    Scene super;
    Node* root;
} MainScene;

Scene* MainScene_Create();