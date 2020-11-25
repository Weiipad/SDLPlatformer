#include "my_math.h"

#include <math.h>

Vec2 Vec2_Create(float x, float y)
{
    Vec2 self = {};
    self.x = x;
    self.y = y;
    return self;
}

Vec2 Vec2_ProjX(Vec2 self)
{
    return Vec2_Create(self.x, 0.0f);
}

Vec2 Vec2_ProjY(Vec2 self)
{
    return Vec2_Create(0.0f, self.y);
}

Vec2 Vec2_Add(Vec2 self, Vec2 rhs)
{
    return Vec2_Create(self.x + rhs.x, self.y + rhs.y);
}

Vec2 Vec2_Sub(Vec2 self, Vec2 rhs)
{
    return Vec2_Create(self.x - rhs.x, self.y - rhs.y);
}

Vec2 Vec2_Mul(Vec2 self, float rhs)
{
    return Vec2_Create(self.x * rhs, self.y * rhs);
}

Vec2 Vec2_Div(Vec2 self, float rhs)
{
    return Vec2_Create(self.x / rhs, self.y / rhs);
}

float Vec2_Dot(Vec2 self, Vec2 rhs)
{
    return self.x * rhs.x + self.y * rhs.y;
}

float Vec2_Magnitude(Vec2 self)
{
    return (float)sqrt((double)Vec2_Dot(self, self));
}

int RectIncludes(Rect* self, Vec2 v)
{
    Vec2 half_size = Vec2_Div(self->size, 2.0);
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
    Vec2 half_size = Vec2_Div(rhs->size, 2.0);
    Vec2 right_bottom = Vec2_Add(*rhs->pos, half_size);

    return 
    RectIncludes(self, Vec2_Sub(*rhs->pos, half_size)) ||
    RectIncludes(self, right_bottom) ||
    RectIncludes(self, Vec2_Sub(right_bottom, Vec2_ProjY(rhs->size))) ||
    RectIncludes(self, Vec2_Sub(right_bottom, Vec2_ProjX(rhs->size)));
}