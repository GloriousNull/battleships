//
// Created by GloriousSir on 10/10/2020.
//

#include <iostream>
#include <future>

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

void std_game::prepare_player(std::unique_ptr<std_player_base> & player_to_prepare)
{
    while (!player_to_prepare->is_ready())
    {
        bool placed{player_to_prepare->place_ship(input_handler->get_ship(), {input_handler->get_coordinate(), input_handler->get_coordinate()})};

        // temporary solution
        if (placed)
            std::cout << "placed\n";
        else
            std::cout << "not placed\n";
    }
}

bool std_game::main_loop()
{
    //TODO
}

void std_game::run_impl()
{
    prepare_player(player_0);
    prepare_player(player_1);

    main_loop();
}