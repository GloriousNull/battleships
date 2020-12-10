//
// Created by GloriousSir on 10/9/2020.
//

#include "game.h"

void game::run()
{
    running = true;

    while (running)
    {
        running = current_game_state->process_input();

        if (!running && next_state)
        {
            current_game_state = std::move(next_state);
            running = true;
        }

        user_interface->render(current_game_state);
    }
}
