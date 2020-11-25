#pragma once

#include "sdl_header.h"
#include "scene.h"

typedef struct GameState {
    SDL_Window* window;
    SDL_Renderer* renderer;

    unsigned char running;

    Scene* current_scene;
} GameState;

GameState* GetGameState();

void GameStateInit(GameState* self, Scene* scene);

void GameStateShiftScene(GameState* self, Scene* scene);

void GameStateRun(GameState* self);

void GameStateDestroy(GameState* self);