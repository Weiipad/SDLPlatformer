#pragma once

#include "sdl_header.h"

int Approximate(float v1, float v2);

float Clamp(float v, float min, float max);

int Sign(float x);

float ClampRound(float v, float radius);

typedef struct Vec2 
{
    float x;
    float y;
} Vec2;

void Vec2_Log(const Vec2* self);

Vec2 Vec2_Create(float x, float y);

Vec2 Vec2_ProjX(Vec2 self);

Vec2 Vec2_ProjY(Vec2 self);

Vec2 Vec2_Add(Vec2 self, Vec2 rhs);

void Vec2_AddAssign(Vec2* self, Vec2 rhs);

Vec2 Vec2_Sub(Vec2 self, Vec2 rhs);

Vec2 Vec2_Mul(Vec2 self, float rhs);

Vec2 Vec2_Div(Vec2 self, float rhs);

void Vec2_DivAssign(Vec2* self, float rhs);

float Vec2_Dot(Vec2 self, Vec2 rhs);

float Vec2_Magnitude(Vec2 self);

Vec2 Vec2_Normalize(Vec2 self);

typedef struct Rect 
{
    Vec2 pos;
    Vec2 size;
} Rect;


int Rect_Includes(const Rect* self, Vec2 v);

int Rect_Overlaps(const Rect* self, const Rect* rhs);

int Rect_OverlapsSDLRect(const Rect* self, const SDL_Rect* rhs);