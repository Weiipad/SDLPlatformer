#pragma once

#include "my_math.h"
#include <stdlib.h>

typedef struct Node 
{
    void* self;
    void (*init)(void* self);
    void (*update)(void* self, float deltaTime);
    void (*draw)(void* self, Vec2 offset);
    void (*destroy)(void* self);

    Vec2 position;

    struct Node* next;
    struct Node* children;
} Node;

void Node_Init(Node* self);

void Node_Update(Node* self, float deltaTime);

void Node_Draw(Node* self, Vec2 offset);

void Node_Destroy(Node* self);