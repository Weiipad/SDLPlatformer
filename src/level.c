#include "level.h"

int Level_Collides(Level* self, const Rect* collider)
{
    for (int i = 0; i < self->tiles.size; i++)
    {
        Rect* current = ArrayList_Get(&self->tiles, i);
        if (Rect_Overlaps(current, collider))
        {
            return 1;
        }
    }
    return 0;
}

Level* Level_Create(SDL_Surface* level)
{
    Level* self = (Level*)malloc(sizeof(Level));

    self->tiles = ArrayList_CreateEmpty(sizeof(Rect));
    
    return 0;
}