#include "game_state.h"

static GameState* instance;

const static Uint8 FPS = 1000/120;

GameState* GetGameState()
{
    if (!instance) instance = (GameState*)malloc(sizeof(GameState));
    return instance;
}

void GameState_Init(GameState* self, Scene* scene)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Failed to init sdl, exiting");
    }

    Vec2 screen_size = Vec2_Create(800, 600);

    self->screen_rect.pos = Vec2_Create(0, 0);
    self->screen_rect.size = screen_size;

    self->window = SDL_CreateWindow("SDL Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_size.x, screen_size.y, SDL_WINDOW_SHOWN);
    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);
    self->running = 1;
    self->current_scene = scene;
}

void GameState_ShiftScene(GameState* self, Scene* scene)
{
    if (!scene) return;
    Scene_Destroy(self->current_scene);
    Scene_Start(scene);
    self->current_scene = scene;
}

void GameState_Run(GameState* self)
{
    Scene_Start(self->current_scene);

    SDL_Event e;
    Uint32 prev_tick = SDL_GetTicks();
    while (self->running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                self->running = 0;
            }
        }

        if (SDL_GetTicks() - prev_tick < FPS)
        {
            SDL_Delay(FPS - SDL_GetTicks() + prev_tick);
        }

        self->deltaTime = (float)(SDL_GetTicks() - prev_tick) / 1000.0f;
        prev_tick = SDL_GetTicks();
        Scene_Update(self->current_scene);

        SDL_RenderPresent(self->renderer);

        
    }
}

void GameState_Destroy(GameState* self)
{
    Scene_Destroy(self->current_scene);
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    SDL_Quit();

    free(self);
}