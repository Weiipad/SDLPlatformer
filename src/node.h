#pragma once

typedef struct Node {
    void* self;
    void (*init)(void* self);
    void (*update)(void* self);
} Node;