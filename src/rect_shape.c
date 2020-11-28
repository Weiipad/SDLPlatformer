#include "rect_shape.h"

#include "sdl_header.h"
#include "game_state.h"

#include "color.h"

void RectShape_Update(void* self_, Vec2 offset_)
{
    RectShape* self = (RectShape*)self_;
}

void RectShape_Draw(void* self_, Vec2 offset_)
{
    RectShape* self = (RectShape*)self_;
    SDL_Renderer* renderer = GetGameState()->renderer;

    SDL_Rect rect = {};
    rect.x = self->super.position.x + offset_.x;
    rect.y = self->super.position.y + offset_.y;
    rect.w = self->size.x;
    rect.h = self->size.y;

    uint8_t r, g, b, a;
    GetColorRGBA(self->color, &r, &g, &b, &a);

    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawRect(renderer, &rect);
}

void RectShape_Destroy(void* self_)
{
    
}

Node* RectShape_Create(uint32_t color, Vec2 position, Vec2 size)
{
    RectShape* self = (RectShape*)malloc(sizeof(RectShape));

    self->super.self = self;
    self->super.init = 0;
    self->super.update = RectShape_Update;
    self->super.draw = RectShape_Draw;
    self->super.destroy = RectShape_Destroy;

    self->super.children = 0;
    self->super.next = 0;
    self->super.position = position;

    self->size = size;

    self->color = color;

    return &self->super;
}