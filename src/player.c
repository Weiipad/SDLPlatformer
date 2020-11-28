#include "player.h"

#include "sdl_header.h"
#include "game_state.h"

static int ground = 0;

static float xRemainder = 0;
static float yRemainder = 0;

static float getMoveDir(const Uint8* key);

static void tryMove(Player* self, Vec2 amount)
{
    Rect target = {};
    target.pos = self->super.position;
    target.size = self->size;

    /*
    xRemainder += amount.x;
    int moveX = (int)roundf(xRemainder);
    if (moveX != 0)
    {
        xRemainder -= moveX;
        int sign = Sign(moveX);
        while (moveX != 0)
        {
            if (!Level_Collides(self->current_level, &target, 0))
            {
                target.pos.x += sign;
                moveX -= sign;
            }
            else
            {
                self->velocity.x = 0;
                break;
            }
        }
    }

    self->super.position.x = target.pos.x;

    yRemainder += amount.y;
    int moveY = (int)roundf(yRemainder);
    if (moveY != 0)
    {
        yRemainder -= moveY;
        int sign = Sign(moveY);
        while (moveY != 0)
        {
            if (!Level_Collides(self->current_level, &target, 0))
            {
                target.pos.y += sign;
                moveY -= sign;
            }
            else
            {
                self->velocity.y = 0;
                break;
            }
        }
    }

    self->super.position.y = target.pos.y;
    */
    
    Rect collide;
    
    // Move X
    float dx = amount.x / 4.0f;
    target.pos.x += amount.x;
    for (int i = 0; i < 4; i++)
    {
        if (Level_Collides(self->current_level, &target, &collide))
        {
            if (amount.x > 0)
            {
                target.pos.x = collide.pos.x - target.size.x;
            }
            else if (amount.x < 0)
            {
                target.pos.x = collide.pos.x + collide.size.x;
            }
            self->velocity.x = 0;
            break;
        }
    }
    self->super.position.x = target.pos.x;

    // Move Y
    float dy = amount.y / 4.0f;
    for (int i = 0; i < 4; i++)
    {
        target.pos.y += dy;
        if (Level_Collides(self->current_level, &target, &collide))
        {
            if (amount.y > 0)
            {
                target.pos.y = collide.pos.y - target.size.y;
                ground = 1;
            }
            else if (amount.y < 0)
            {
                target.pos.y = collide.pos.y + collide.size.y;
            }
            self->velocity.y = 0;

            break;
        }
    }
    self->super.position.y = target.pos.y;
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
    
    if (key[SDL_SCANCODE_C])
    {
        if (!self->jumpDown && ground)
        {
            self->velocity.y -= 4.5f;
            ground = 0;
            self->jumpDown = 1;
        }
    }
    else
    {
        self->jumpDown = 0;
    }
    

    self->velocity.x = ClampRound(self->velocity.x, 3.25f);
    if (Approximate(self->velocity.x, 0))
    {
        self->velocity.x = 0;
    }

    tryMove(self, self->velocity);
}

Player* Player_Create(Level* current_level, Vec2 start, Vec2 size)
{
    Player* self = (Player*)calloc(1, sizeof(Player));

    self->super.self = self;
    self->super.update = Player_Update;
    self->super.position = start;

    self->current_level = current_level;

    self->velocity = Vec2_Create(0, 0);

    self->size = size;
    self->jumpDown = 0;

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