#include "game_state.h"

static GameState* instance;

GameState* GetGameState()
{
    if (!instance) instance = malloc(sizeof(GameState));
    return instance;
}

void GameStateInit(GameState* self, Scene* scene)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Failed to init sdl, exiting");
    }

    self->window = SDL_CreateWindow("SDL Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);
    self->running = 1;
    self->current_scene = scene;
}

void GameStateShiftScene(GameState* self, Scene* scene)
{
    if (!scene) return;
    SceneDestroy(self->current_scene);
    SceneStart(scene);
    self->current_scene = scene;
}

void GameStateRun(GameState* self)
{
    SceneStart(self->current_scene);

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

        Uint32 now_tick = SDL_GetTicks();

        float deltaTime = (float)(now_tick - prev_tick) / 1000.0f;

        SceneUpdate(self->current_scene, deltaTime);

        SDL_RenderPresent(self->renderer);
    }
}

void GameStateDestroy(GameState* self)
{
    SceneDestroy(self->current_scene);
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    SDL_Quit();

    free(self);
}