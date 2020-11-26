#include "scene.h"
#include <stdlib.h>

void Scene_Start(Scene* self)
{
    self->start(self->self);
}

void Scene_Update(Scene* self)
{
    self->update(self->self);
}

void Scene_Destroy(Scene* self)
{
    self->destroy(self->self);
    free(self->self);
}