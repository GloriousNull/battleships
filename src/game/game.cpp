//
// Created by GloriousSir on 10/9/2020.
//

#include "game.h"

void game::run()
{
    running = true;

    while (running)
    {
        running = game_state->process_input();

        user_interface->render(game_state);
    }
}
