#include <stdio.h>
#include "sdl_header.h"
#include "main_scene.h"
#include "game_state.h"

int main(int argc, char** argv)
{
    GameState* game = GetGameState();

    GameState_Init(game, MainScene_Create());
    GameState_Run(game);
    GameState_Destroy(game);
    return 0;
}