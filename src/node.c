#include "node.h"


void Node_PushChild(Node* self, Node* child)
{
    if (!child) return;

    child->next = self->children;
    self->children = child;
}

void Node_PopChild(Node* self)
{
    if (!self) return;

    Node* child = self->children;
    self->children = child->next;
    child->next = 0;

    Node_Destroy(child);
}

void Node_Init(Node* self)
{
    if (!self) return;

    if (self->init) self->init(self->self);
    for (Node* i = self->children; i; i = i->next)
    {
        Node_Init(i);
    }
}

void Node_Update(Node* self, float deltaTime)
{
    if (!self) return;

    if (self->update) self->update(self->self, deltaTime);
    for (Node* i = self->children; i; i = i->next)
    {
        Node_Update(i, deltaTime);
    }
}

void Node_Draw(Node* self, Vec2 offset_)
{
    if (!self) return;

    if (self->draw) self->draw(self->self, offset_);

    Vec2 offset = Vec2_Add(self->position, offset_);
    for (Node* i = self->children; i; i = i->next)
    {
        Node_Draw(i, offset);
    }
}

void Node_Destroy(Node* self)
{
    if (!self) return;

    while (self->children)
    {
        Node_PopChild(self);
    }
    if (self->destroy) self->destroy(self->self);
    if (self->self) free(self->self);
}