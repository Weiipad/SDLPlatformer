#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>

#include "sprite.h"
#include "rect_shape.h"

void MainScene_Start(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;
    SDL_Surface* img = SDL_LoadBMP("assets/dummy.bmp");

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);
    

    Node* rect = RectShape_Create(Vec2_Create(50, 50), Vec2_Create(100, 100));

    Node_PushChild(self->root, Sprite_Create(texture, Vec2_Create(100.0f, 100.0f)));
    Node_PushChild(self->root, rect);


    Node_Init(self->root);
}

void MainScene_Update(void* self_, float deltaTime)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    Node_Update(self->root, deltaTime);
    Node_Draw(self->root, Vec2_Create(0, 0));
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0, 0);
    SDL_Rect dst = { 100, 0, 100, 100};
    SDL_RenderFillRect(renderer, &dst);
}

void MainScene_Destroy(void* self_)
{
    MainScene* self = (MainScene*)self_;
    Node_Destroy(self->root);
    free(self->root);
}

Scene* MainScene_Create()
{
    MainScene* obj = (MainScene*)malloc(sizeof(MainScene));

    obj->vtable.self = obj;
    obj->vtable.start = MainScene_Start;
    obj->vtable.update = MainScene_Update;
    obj->vtable.destroy = MainScene_Destroy;

    obj->root = (Node*)malloc(sizeof(Node));
    obj->root->self = 0;
    obj->root->position = Vec2_Create(0, 0);
    obj->root->next = 0;
    obj->root->children = 0;

    return &obj->vtable;
}


