#pragma once

#include <math.h>

typedef struct Vec2 
{
    float x, y;
} Vec2;

Vec2 Vec2ProjX(Vec2 self)
{
    return { self.x, 0.0f };
}

Vec2 Vec2ProjY(Vec2 self)
{
    return { 0.0f, self.y };
}

Vec2 Vec2Add(Vec2 self, Vec2 rhs)
{
    return { self.x + rhs.x, self.y + rhs.y };
}

Vec2 Vec2Sub(Vec2 self, Vec2 rhs)
{
    return { self.x - rhs.x, self.y - rhs.y };
}

Vec2 Vec2Mul(Vec2 self, float rhs)
{
    return { self.x * rhs, self.y * rhs };
}

Vec2 Vec2Div(Vec2 self, float rhs)
{
    return { self.x / rhs, self.y / rhs };
}

float Vec2Dot(Vec2 self, Vec2 rhs)
{
    return self.x * rhs.x + self.y * rhs.y;
}

float Vec2Magnitude(Vec2 self)
{
    return sqrt(Vec2Dot(self, self));
}

typedef struct Rect 
{
    Vec2* pos;
    Vec2 size;
} Rect;


int RectIncludes(Rect* self, Vec2 v)
{
    Vec2 half_size = Vec2Div(self->size, 2.0);
    float left = self->pos->x - half_size.x;
    float right = self->pos->x + half_size.x;
    float top = self->pos->y - half_size.y;
    float bottom = self->pos->y + half_size.y;

    if (v.x < left || v.x > right) return 0;
    if (v.y < top || v.y > bottom) return 0;
    return 1;
}

int RectOverlaps(Rect* self, Rect* rhs)
{
    Vec2 half_size = Vec2Div(rhs->size, 2.0);
    Vec2 right_bottom = Vec2Add(*rhs->pos, half_size);

    return 
    RectIncludes(self, Vec2Sub(*rhs->pos, half_size)) ||
    RectIncludes(self, right_bottom) ||
    RectIncludes(self, Vec2Sub(right_bottom, Vec2ProjY(rhs->size))) ||
    RectIncludes(self, Vec2Sub(right_bottom, Vec2ProjX(rhs->size)));
}