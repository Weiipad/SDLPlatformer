#pragma once

typedef struct Scene 
{
    void* self;
    void (*start)(void* self);
    void (*update)(void* self, float deltaTime);
    void (*destroy)(void* self);
} Scene;

void Scene_Start(Scene* self);

void Scene_Update(Scene* self, float deltaTime);

void Scene_Destroy(Scene* self);
