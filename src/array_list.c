#include "array_list.h"

#include <stdlib.h>
#include <string.h>

ArrayList ArrayList_CreateWithSize(int size, int dataSize)
{
    ArrayList self = {};
    self.array = malloc(size * dataSize);
    self.capacity = size;
    self.ptr = size;
    self.dataSize = dataSize;

    return self;
}

ArrayList ArrayList_CreateEmpty(int dataSize)
{
    ArrayList self = ArrayList_CreateWithSize(8, dataSize);
    self.ptr = 0;
    return self;
}

void ArrayList_PushBack(ArrayList* self, const void* v)
{
    if (self->ptr >= self->capacity)
    {
        void* temp = malloc(self->capacity * 2 * self->dataSize);
        memcpy(temp, self->array, self->capacity * self->dataSize);
        free(self->array);
        self->capacity *= 2;
        self->array = temp;
    }
    memcpy(self->array + self->ptr * self->dataSize, v, self->dataSize);
    self->ptr += 1;
}

void ArrayList_PopBack(ArrayList* self)
{
    self->ptr -= 1;
}

void* ArrayList_Get(const ArrayList* self, int index)
{
    if (index > self->ptr) return 0;
    return self->array + index * self->dataSize;
}

void ArrayList_Set(const ArrayList* self, int index, const void* v)
{
    if (index > self->ptr) return;
    memcpy(self->array + index * self->dataSize, v, self->dataSize);
}

void ArrayList_Destroy(ArrayList* self)
{
    free(self->array);
}