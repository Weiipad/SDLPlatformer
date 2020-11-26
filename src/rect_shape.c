#include "rect_shape.h"

#include "sdl_header.h"
#include "game_state.h"

void RectShape_Draw(void* self_, Vec2 offset)
{
    RectShape* self = (RectShape*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;
    SDL_Rect rect = {};
    rect.x = self->super.position.x + offset.x;
    rect.y = self->super.position.y + offset.y;
    rect.w = self->rect.size.x;
    rect.h = self->rect.size.y;


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderFillRect(renderer, &rect);
}

Node* RectShape_Create(Vec2 position, Vec2 size)
{
    RectShape* self = (RectShape*)malloc(sizeof(RectShape));

    self->super.self = self;
    self->super.init = 0;
    self->super.update = 0;
    self->super.draw = RectShape_Draw;
    self->super.children = 0;
    self->super.next = 0;
    self->super.position = position;

    self->rect.pos = &self->super.position;
    self->rect.size = size;

    return &self->super;
}