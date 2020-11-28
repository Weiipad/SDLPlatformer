#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>

#include "sprite.h"
#include "rect_shape.h"

void MainScene_Start(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    SDL_Surface* level = SDL_LoadBMP("assets/map.bmp");

    if (!level)
    {
        SDL_Log("Failed to load dummy.bmp!");
        exit(-1);
    }

    self->camera_position = Vec2_Create(0, 0);

    self->level = Level_Create(level);

    self->player = Player_Create(self->level, Vec2_Create(175, 75), Vec2_Create(35, 45));

    Node_PushChild(self->root, &(self->level->node));

    Node_PushChild(&self->player->super, RectShape_Create(0xff0000ff, Vec2_Create(0, 0), Vec2_Create(35, 45)));
    
    Node_PushChild(self->root, &self->player->super);

    Node_Init(self->root);
}

void MainScene_Update(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    const Uint8* key = SDL_GetKeyboardState(0);

    // tracing smoothly.
    Vec2_AddAssign(&self->camera_position, Vec2_Mul(Vec2_Sub(self->player->super.position, self->camera_position), 0.125f));
    // impl camera.
    self->root->position = Vec2_Neg(Vec2_Sub(self->camera_position, Vec2_Create(400, 300)));

    Node_Update(self->root, Vec2_Create(0, 0));
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

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


