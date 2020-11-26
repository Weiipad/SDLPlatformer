#pragma once

#include "sdl_header.h"
#include "scene.h"

typedef struct GameState 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    Scene* current_scene;

    int running;
    float deltaTime;
} GameState;

GameState* GetGameState();

void GameState_Init(GameState* self, Scene* scene);

void GameState_ShiftScene(GameState* self, Scene* scene);

void GameState_Run(GameState* self);

void GameState_Destroy(GameState* self);