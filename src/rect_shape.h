#pragma once

#include "node.h"
#include "my_math.h"
#include <stdint.h>

typedef struct RectShape {
    Node super;
    Vec2 size;
    uint32_t color;
} RectShape;

Node* RectShape_Create(uint32_t color, Vec2 position, Vec2 size);