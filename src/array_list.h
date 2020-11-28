#pragma once

typedef struct ArrayList
{
    void* array;
    int size;
    int capacity;

    int dataSize;
} ArrayList;

ArrayList ArrayList_CreateEmpty(int dataSize);

ArrayList ArrayList_CreateWithSize(int size, int dataSize);

void ArrayList_PushBack(ArrayList* self, const void* v);

void ArrayList_PopBack(ArrayList* self);

void* ArrayList_Get(const ArrayList* self, int index);

void ArrayList_Set(const ArrayList* self, int index, const void* v);

void ArrayList_Destroy(ArrayList* self);