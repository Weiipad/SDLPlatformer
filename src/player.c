#include "player.h"

#include "sdl_header.h"
#include "game_state.h"

static int ground = 0;

static float getMoveDir(const Uint8* key);

static void tryMoveTo(Player* self, Vec2 amount)
{
    float targetX = self->super.position.x + amount.x;
    if (targetX >= 800 - self->collider.size.x)
    {
        targetX = 800 - self->collider.size.x;
        self->velocity.x = 0;
    }

    if (targetX <= 0)
    {
        targetX = 0;
        self->velocity.x = 0;
    }
    self->super.position.x = targetX;
    float targetY = self->super.position.y + amount.y;
    if (targetY >= 300 - self->collider.size.y)
    {
        targetY = 300 - self->collider.size.y;
        self->velocity.y = 0;
        ground = 1;
    }

    if (targetY <= 0)
    {
        targetY = 0;
        self->velocity.y = 0;
    }
    self->super.position.y = targetY;
}

void Player_Update(void* self_, Vec2 offset_)
{
    Player* self = (Player*)self_;
    const Uint8* key = SDL_GetKeyboardState(0);
    float dir = getMoveDir(key);

    Vec2 acc = Vec2_Create(dir * 8.0f, 9.8);
    if (dir == 0 && ground)
    {
        acc.x = -self->velocity.x * 20.0f;
        
    }

    if (dir * self->velocity.x < 0)
    {
        if (ground)
        {
            acc.x *= 4.0f;
        }
        else
        {
            acc.x = 0.0f;
        }
        
    }
    

    Vec2_AddAssign(&self->velocity, Vec2_Mul(acc, GetGameState()->deltaTime));
    
    if (key[SDL_SCANCODE_C] && ground)
    {
        self->velocity.y -= 4.5f;
        ground = 0;
    }

    self->velocity.x = ClampRound(self->velocity.x, 3.5f);
    if (Approximate(self->velocity.x, 0))
    {
        self->velocity.x = 0;
    }

    tryMoveTo(self, self->velocity);

    Vec2_Log(&self->super.position);
}

Player* Player_Create(Vec2 start, Vec2 size)
{
    Player* self = (Player*)calloc(1, sizeof(Player));

    self->super.self = self;
    self->super.update = Player_Update;
    self->super.position = start;

    self->velocity = Vec2_Create(0, 0);

    self->collider.size = size;

    return self;
}

static float getMoveDir(const Uint8* key)
{
    float dir = 0;
    if (key[SDL_SCANCODE_LEFT])
    {
        dir -= 1;
    }

    if (key[SDL_SCANCODE_RIGHT])
    {
        dir += 1;
    }

    return dir;
}