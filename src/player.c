#include "player.h"

#include "sdl_header.h"
#include "game_state.h"

static Vec2 getMoveDir(const Uint8* key);

static void tryMoveX(Player* self, float amount)
{
    
}

void Player_Update(void* self_, Vec2 offset_)
{
    Player* self = (Player*)self_;
    const Uint8* key = SDL_GetKeyboardState(0);
    Vec2 dir = getMoveDir(key);

    Vec2_AddAssign(&self->velocity, Vec2_Mul(dir, 1.0f * GetGameState()->deltaTime));

    self->velocity.x = Clamp(self->velocity.x, -2, 2);
    self->velocity.y = Clamp(self->velocity.y, -2, 2);

    Vec2_AddAssign(&self->super.position, self->velocity);
}

Player* Player_Create(Vec2 start)
{
    Player* self = (Player*)malloc(sizeof(Player));

    memset(self, 0, sizeof(Player));

    self->super.self = self;
    self->super.update = Player_Update;
    self->super.position = start;

    self->velocity = Vec2_Create(0, 0);

    return self;
}

static Vec2 getMoveDir(const Uint8* key)
{
    Vec2 dir = Vec2_Create(0, 0);
    if (key[SDL_SCANCODE_LEFT])
    {
        dir.x -= 1;
    }

    if (key[SDL_SCANCODE_RIGHT])
    {
        dir.x += 1;
    }

    if (key[SDL_SCANCODE_UP])
    {
        dir.y -= 1;
    }

    if (key[SDL_SCANCODE_DOWN])
    {
        dir.y += 1;
    }

    return Vec2_Normalize(dir);
}