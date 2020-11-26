#pragma once

#include "my_math.h"
#include <stdlib.h>

typedef struct Node 
{
    void* self;
    void (*init)(void* self);
    void (*update)(void* self, Vec2 offset);
    void (*draw)(void* self, Vec2 offset);
    void (*destroy)(void* self);

    Vec2 position;

    struct Node* next;
    struct Node* children;
} Node;

void Node_PushChild(Node* self, Node* child);

// Delete the first child in children.
void Node_PopChild(Node* self);

void Node_Init(Node* self);

void Node_Update(Node* self, Vec2 offset);

void Node_Draw(Node* self, Vec2 offset);

void Node_Destroy(Node* self);

typedef struct Dummy
{
    Node super;
} Dummy;

Node* Dummy_Create();