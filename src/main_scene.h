#pragma once

#include "scene.h"
#include "node.h"

typedef struct MainScene 
{
    Scene vtable;
    Node root;
} MainScene;

Scene* MainScene_Create();