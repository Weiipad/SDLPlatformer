#include "my_math.h"

#include "sdl_header.h"

int Approximate(float v1, float v2)
{
    return SDL_fabsf(v1 - v2) < 1e-3;
}

float Clamp(float v, float min, float max)
{
    if (v < min) return min;
    if (v > max) return max;
    return v;
}

float ClampRound(float v, float radius)
{
    return Clamp(v, -radius, radius);
}

int Sign(float x)
{
    if (x > 0) return 1;
    if (x == 0) return 0;
    if (x < 0) return -1;
}

void Vec2_Log(const Vec2* self)
{
    SDL_Log("(%f, %f)", self->x, self->y);
}

Vec2 Vec2_Create(float x, float y)
{
    Vec2 self = {};
    self.x = x;
    self.y = y;
    return self;
}

Vec2 Vec2_ProjX(Vec2 self)
{
    self.y = 0;
    return self;
}

Vec2 Vec2_ProjY(Vec2 self)
{
    self.x = 0;
    return self;
}

Vec2 Vec2_Add(Vec2 self, Vec2 rhs)
{
    self.x += rhs.x;
    self.y += rhs.y;
    return self;
}

void Vec2_AddAssign(Vec2* self, Vec2 rhs)
{
    self->x += rhs.x;
    self->y += rhs.y;
}

Vec2 Vec2_Sub(Vec2 self, Vec2 rhs)
{
    self.x -= rhs.x;
    self.y -= rhs.y;
    return self;
}

Vec2 Vec2_Mul(Vec2 self, float rhs)
{
    self.x *= rhs;
    self.y *= rhs;
    return self;
}

Vec2 Vec2_Div(Vec2 self, float rhs)
{
    self.x /= rhs;
    self.y /= rhs;
    return self;
}

void Vec2_DivAssign(Vec2* self, float rhs)
{
    self->x /= rhs;
    self->y /= rhs;
}

float Vec2_Dot(Vec2 self, Vec2 rhs)
{
    return self.x * rhs.x + self.y * rhs.y;
}

float Vec2_Magnitude(Vec2 self)
{
    return SDL_sqrtf(Vec2_Dot(self, self));
}

Vec2 Vec2_Normalize(Vec2 self)
{
    float magnitude = Vec2_Magnitude(self);
    if (Approximate(magnitude, 0)) return Vec2_Create(0, 0);
    Vec2_DivAssign(&self, magnitude);
    return self;
}

Vec2 Vec2_Neg(Vec2 self)
{
    self.x = -self.x;
    self.y = -self.y;
    return self;
}

int Rect_Includes(const Rect* self, Vec2 v)
{
    float right = self->pos.x + self->size.x;
    float bottom = self->pos.y + self->size.y;

    if (v.x <= self->pos.x || v.x >= right) return 0;
    if (v.y <= self->pos.y || v.y >= bottom) return 0;
    return 1;
}

int Rect_Overlaps(const Rect* self, const Rect* rhs)
{
    Vec2 right_bottom = Vec2_Add(rhs->pos, rhs->size);

    return 
        Rect_Includes(self, rhs->pos) ||
        Rect_Includes(self, right_bottom) ||
        Rect_Includes(self, Vec2_Sub(right_bottom, Vec2_ProjY(rhs->size))) ||
        Rect_Includes(self, Vec2_Sub(right_bottom, Vec2_ProjX(rhs->size)));
}

int Rect_OverlapsSDLRect(const Rect* self, const SDL_Rect* rhs)
{
    return 
        Rect_Includes(self, Vec2_Create(rhs->x, rhs->y)) ||
        Rect_Includes(self, Vec2_Create(rhs->x + rhs->w, rhs->y + rhs->h)) ||
        Rect_Includes(self, Vec2_Create(rhs->x + rhs->w, rhs->y)) ||
        Rect_Includes(self, Vec2_Create(rhs->x, rhs->y + rhs->h));
}