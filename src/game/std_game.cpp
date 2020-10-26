//
// Created by GloriousSir on 10/10/2020.
//

#include <iostream>
#include <future>

#include "std_game.h"
#include "../players/std_player.h"
#include "../ships/std_ship.h"

std_game::std_game(std::unique_ptr<input_handler_base> && input, std::unique_ptr<user_interface_base> && interface)
{
    this->input_handler = std::move(input);
    interface->link_game(this);
    this->user_interface = std::move(interface);

    this->player_0 = std::make_unique<std_player>();
    this->player_1 = std::make_unique<std_player>();

    this->running = false;
}

bool std_game::is_running_impl() const
{
    return this->running;
}

const std::unique_ptr<std_player_base> & std_game::get_active_player_impl() const
{
    return player_0;
}

// TODO: make event-driven system?

void std_game::prepare_player(std::unique_ptr<std_player_base> & player_to_prepare)
{
    std::size_t ship_length{STD_MAX_SHIP_LENGTH},
                number_of_ships{STD_STARTER_AMOUNT_OF_SHIPS},
                original_number_of_ships{STD_STARTER_AMOUNT_OF_SHIPS};

    while (!player_to_prepare->is_ready())
    {
        std::cout << "Place ship of size " << ship_length << '\n';

        bool placed{player_to_prepare->place_ship(std::make_shared<std_ship>(ship_length),
                   {input_handler->get_coordinate(), input_handler->get_coordinate()})};

        if (placed)
        {
            std::cout << "Ship placed\n";

            if (!--number_of_ships)
            {
                --ship_length;
                number_of_ships = ++original_number_of_ships;
            }
        }
        else
        {
            std::cout << "failed to place the ship\n";
        }
    }
}

void std_game::main_loop()
{
    while (running)
    {
        auto[revealed, hit] = player_0->attack(player_1, input_handler->get_coordinate());

        if (revealed)
        {
            std::cout << "Revealed\n";

            player_0.swap(player_1);
        }

        if (hit)
        {
            std::cout << "Hit!\n";

            if (player_0->amount_of_owned_ships() == 0)
            {
                std::cout << "Game over\n";

                running = false;
            }
        }
    }
}

void std_game::run_impl()
{
    running = true;

    std::cout << "Preparation phase started\n";

    prepare_player(player_0);
    prepare_player(player_1);

    std::cout << "Preparation phase ended\nGame started\n";

    main_loop();
}