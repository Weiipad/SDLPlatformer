#include "scene.h"
#include <stdlib.h>

void SceneStart(Scene* _self)
{
    _self->start(_self->self);
}

void SceneUpdate(Scene* _self, float deltaTime)
{
    _self->update(_self->self, deltaTime);
}

void SceneDestroy(Scene* _self)
{
    _self->destroy(_self->destroy);
    free(_self->self);
}