#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>


void MainScene_Start(void* self)
{
    
}

void MainScene_Update(void* self, float deltaTime)
{
    SDL_Renderer* renderer = GetGameState()->renderer;
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);
}

void MainScene_Destroy(void* self)
{
    
}

Scene* MainScene_Create()
{
    MainScene* obj = (MainScene*)malloc(sizeof(MainScene));
    obj->vtable.self = obj;
    obj->vtable.start = MainScene_Start;
    obj->vtable.update = MainScene_Update;
    obj->vtable.destroy = MainScene_Destroy;
    return &obj->vtable;
}


