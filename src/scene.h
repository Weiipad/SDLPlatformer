#pragma once

typedef struct Scene {
    void* self;
    void (*start)(void* self);
    void (*update)(void* self, float deltaTime);
    void (*destroy)(void* self);
} Scene;

void SceneStart(Scene* self);

void SceneUpdate(Scene* self, float deltaTime);

void SceneDestroy(Scene* self);
