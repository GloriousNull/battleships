//
// Created by GloriousSir on 10/10/2020.
//

#include "std_game.h"
#include "../players/std_player.h"

std_game::std_game(std::unique_ptr<input_handler_base> input)
{
    this->input_handler = std::move(input);
    this->player_0 = std::make_unique<std_player>();
    this->player_1 = std::make_unique<std_player>();

    this->running = false;
}

bool std_game::is_running_impl() const
{
    return this->running;
}

bool std_game::preparation_phase()
{
    while (!player_0->is_ready() || !player_1->is_ready())
    {

    }
}

bool std_game::main_loop()
{

}

void std_game::run_impl()
{
    preparation_phase();

    main_loop();
}