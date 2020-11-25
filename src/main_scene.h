#pragma once

#include "scene.h"

typedef struct MainScene 
{
    Scene vtable;
} MainScene;

Scene* NewMainScene();

void MainSceneStart(void* self);

void MainSceneUpdate(void* self, float deltaTime);

void MainSceneDestroy(void* self);