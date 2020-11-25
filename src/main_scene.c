#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>

Scene* NewMainScene()
{
    MainScene* obj = malloc(sizeof(MainScene));
    obj->vtable.self = obj;
    obj->vtable.start = MainSceneStart;
    obj->vtable.update = MainSceneUpdate;
    obj->vtable.destroy = MainSceneDestroy;
    return &obj->vtable;
}

void MainSceneStart(void* _self)
{
    
}

void MainSceneUpdate(void* _self, float deltaTime)
{
    SDL_Renderer* renderer = GetGameState()->renderer;
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
}

void MainSceneDestroy(void* _self)
{
    
}

