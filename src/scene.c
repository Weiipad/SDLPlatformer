#include "scene.h"
#include <stdlib.h>

void SceneStart(Scene* self)
{
    self->start(self->self);
}

void SceneUpdate(Scene* self, float deltaTime)
{
    self->update(self->self, deltaTime);
}

void SceneDestroy(Scene* self)
{
    self->destroy(self->destroy);
    free(self->self);
}