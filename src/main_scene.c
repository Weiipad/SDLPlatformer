#include "main_scene.h"
#include "game_state.h"
#include <stdlib.h>

#include "sprite.h"
#include "rect_shape.h"

Node* dmy = 0;

void MainScene_Start(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;
    SDL_Surface* img = SDL_LoadBMP("assets/dummy.bmp");

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);

    dmy = Dummy_Create();

    Node_PushChild(dmy, Sprite_Create(texture, Vec2_Create(100, 100), Vec2_Create(100.0f, 100.0f)));
    Node_PushChild(dmy, RectShape_Create(Vec2_Create(50, 50), Vec2_Create(100, 100)));
    
    Node_PushChild(self->root, dmy);

    Node_Init(self->root);
}

void MainScene_Update(void* self_)
{
    MainScene* self = (MainScene*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;
    
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    Vec2 dir = Vec2_Create(0, 0);

    const Uint8* key = SDL_GetKeyboardState(0);

    if (key[SDL_SCANCODE_A])
    {
        dir.x -= 1;
    }

    if (key[SDL_SCANCODE_D])
    {
        dir.x += 1;
    }

    if (key[SDL_SCANCODE_W])
    {
        dir.y -= 1;
    }

    if (key[SDL_SCANCODE_S])
    {
        dir.y += 1;
    }

    Vec2 ndir = Vec2_Normalize(dir);

    Vec2_AddAssign(&dmy->position, Vec2_Mul(ndir, 0.05f * GetGameState()->deltaTime));

    Node_Update(self->root, Vec2_Create(0, 0));
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


