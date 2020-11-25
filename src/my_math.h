#pragma once



typedef struct Vec2 
{
    float x;
    float y;
} Vec2;

Vec2 Vec2_Create(float x, float y);

Vec2 Vec2_ProjX(Vec2 self);

Vec2 Vec2_ProjY(Vec2 self);

Vec2 Vec2_Add(Vec2 self, Vec2 rhs);

Vec2 Vec2_Sub(Vec2 self, Vec2 rhs);

Vec2 Vec2_Mul(Vec2 self, float rhs);

Vec2 Vec2_Div(Vec2 self, float rhs);

float Vec2_Dot(Vec2 self, Vec2 rhs);

float Vec2_Magnitude(Vec2 self);

typedef struct Rect 
{
    Vec2* pos;
    Vec2 size;
} Rect;


int RectIncludes(Rect* self, Vec2 v);

int RectOverlaps(Rect* self, Rect* rhs);