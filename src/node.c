#include "node.h"

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

void Node_Draw(Node* self, Vec2 offset)
{
    if (!self) return;

    Vec2 offset_ = Vec2_Add(self->position, offset);

    if (self->draw) self->draw(self->self, offset_);
    for (Node* i = self->children; i; i = i->next)
    {
        Node_Draw(self, offset_);
    }
}

void Node_Destroy(Node* self)
{
    if (!self) return;

    for (Node* i = self->children; i; i = i->next)
    {
        Node_Destroy(i);
    }
    if (self->destroy) self->destroy(self->self);
    free(self->self);
}