#pragma once

#include "node.h"
#include "my_math.h"

typedef struct RectShape {
    Node super;
    Rect rect;
} RectShape;

Node* RectShape_Create(Vec2 position, Vec2 size);