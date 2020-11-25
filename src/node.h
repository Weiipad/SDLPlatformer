#pragma once

#include <stdlib.h>

typedef struct Node 
{
    void* self;
    void (*init)(void* self);
    void (*update)(void* self, float deltaTime);
    void (*destroy)(void* self);

    struct Node* next;
    struct Node* children;
} Node;

void NodeInit(Node* self)
{
    self->init(self->self);
    for (Node* i = self->children; i; i = i->next)
    {
        NodeInit(i);
    }
}

void NodeUpdate(Node* self, float deltaTime)
{
    self->update(self->self, deltaTime);
    for (Node* i = self->children; i; i = i->next)
    {
        NodeUpdate(i, deltaTime);
    }
}

void NodeDestroy(Node* self)
{
    for (Node* i = self->children; i; i = i->next)
    {
        NodeDestroy(i);
    }
    self->destroy(self->self);
    free(self->self);
}