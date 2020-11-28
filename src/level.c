#include "level.h"

#include "game_state.h"

#include "color.h"

const int TILE_SIZE = 50;

static Uint32 getSDLSurfacePixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

int Level_Collides(Level* self, const Rect* collider, Rect* outWhich)
{
    for (int i = 0; i < self->tiles.size; i++)
    {
        Rect* current = ArrayList_Get(&self->tiles, i);
        if (SDL_fabsf(current->pos.x - collider->pos.x) > (TILE_SIZE << 1)) continue;
        if (SDL_fabsf(current->pos.y - collider->pos.y) > (TILE_SIZE << 1)) continue;

        if (Rect_Overlaps(current, collider))
        {
            if (outWhich) *outWhich = *current;
            return 1;
        }
    }
    outWhich = 0;
    return 0;
}

void Level_Draw(void* self_, Vec2 offset_)
{
    Level* self = (Level*)self_;

    Rect* screen = &GetGameState()->screen_rect;
    SDL_Renderer* renderer = GetGameState()->renderer;

    int count = 0;
    SDL_SetRenderDrawColor(renderer, 0, 0xff, 0, 0xff);
    for (int i = 0; i < self->tiles.size; i++)
    {
        Rect* current = ArrayList_Get(&self->tiles, i);
        SDL_Rect r = {};
        r.x = offset_.x + current->pos.x;
        r.y = offset_.y + current->pos.y;
        r.w = TILE_SIZE;
        r.h = TILE_SIZE;

        if (Rect_OverlapsSDLRect(screen, &r))
        {
            SDL_RenderDrawRect(renderer, &r);
            count++;
        }
    }

    SDL_Log("Tile rendered: %d", count);
}

void Level_Destroy(void* self_)
{
    Level* self = (Level*)self_;
    ArrayList_Destroy(&self->tiles);
}

Level* Level_Create(SDL_Surface* level)
{
    Level* self = (Level*)malloc(sizeof(Level));

    self->node.self = self;
    self->node.init = 0;
    self->node.update = 0;
    self->node.draw = Level_Draw;
    self->node.destroy = Level_Destroy;

    self->node.children = 0;
    self->node.next = 0;

    self->tiles = ArrayList_CreateEmpty(sizeof(Rect));

    self->level_map = level;
    self->witdth = level->w;
    self->height = level->h;

    SDL_Log("%d", self->height);

    for (int i = 0; i < self->height; i++)
    {
        for (int j = 0; j < self->witdth; j++)
        {
            if (getSDLSurfacePixel(level, j, i) != 0)
            {
                Rect tile = {};
                tile.pos.x = j * TILE_SIZE;
                tile.pos.y = i * TILE_SIZE;
                tile.size.x = TILE_SIZE;
                tile.size.y = TILE_SIZE;
                ArrayList_PushBack(&self->tiles, &tile);
            }
        }
    }

    return self;
}