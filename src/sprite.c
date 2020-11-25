#include "sprite.h"

#include "game_state.h"

void Sprite_Draw(void* self_, Vec2 offset)
{
    Sprite* self = (Sprite*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    SDL_Rect dst = {};
    dst.x = offset.x;
    dst.y = offset.y;
    dst.w = self->size.x;
    dst.h = self->size.y;
    
    SDL_RenderCopy(renderer, self->texture, 0, &dst);
}

void Sprite_Destroy(void* self_)
{
    Sprite* self = (Sprite*)self_;
    SDL_DestroyTexture(self->texture);
}

Node* Sprite_Create(SDL_Texture* texture, Vec2 size)
{
    Sprite* self = (Sprite*)malloc(sizeof(Sprite));

    self->super.self = self;
    self->super.init = 0;
    self->super.update = 0;
    self->super.draw = Sprite_Draw;
    self->super.destroy = Sprite_Destroy;

    self->super.position = Vec2_Create(0, 0);
    self->super.children = 0;

    self->texture = texture;
    self->size = size;

    return &self->super;
}

