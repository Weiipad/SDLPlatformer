#include <stdio.h>
#include "sdl_header.h"
#include "main_scene.h"
#include "game_state.h"

int main(int argc, char** argv)
{
    GameState* game = GetGameState();

    GameStateInit(game, NewMainScene());
    GameStateRun(game);
    GameStateDestroy(game);
    return 0;
}