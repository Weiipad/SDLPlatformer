#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>

#include "sprite.h"
#include "rect_shape.h"

void MainScene_Start(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    self->player = Player_Create(Vec2_Create(0, 0), Vec2_Create(50, 50));
    Node_PushChild(&self->player->super, RectShape_Create(0xff0000ff, Vec2_Create(0, 0), Vec2_Create(50, 50)));
    
    Node_PushChild(self->root, &self->player->super);

    Node_Init(self->root);
}

void MainScene_Update(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    Node_Update(self->root, Vec2_Create(0, 0));
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderDrawLine(renderer, 0, 300, 800, 300);
    Node_Draw(self->root, Vec2_Create(0, 0));
}

void MainScene_Destroy(void* self_)
{
    MainScene* self = (MainScene*)self_;
    Node_Destroy(self->root);
    free(self->root);
}

Scene* MainScene_Create()
{
    MainScene* self = (MainScene*)malloc(sizeof(MainScene));

    self->super.self = self;
    self->super.start = MainScene_Start;
    self->super.update = MainScene_Update;
    self->super.destroy = MainScene_Destroy;

    self->root = (Node*)malloc(sizeof(Node));
    self->root->self = 0;
    self->root->position = Vec2_Create(0, 0);
    self->root->next = 0;
    self->root->children = 0;

    return &self->super;
}


