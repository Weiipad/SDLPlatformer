#pragma once

typedef struct Scene 
{
    void* self;
    void (*start)(void* self);
    void (*update)(void* self);
    void (*destroy)(void* self);
} Scene;

void Scene_Start(Scene* self);

void Scene_Update(Scene* self);

void Scene_Destroy(Scene* self);
