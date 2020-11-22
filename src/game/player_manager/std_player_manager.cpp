//
// Created by GloriousSir on 10/31/2020.
//

#include "std_player_manager.h"
#include "../../input/concurrent_input_handler_base.h"
#include "../../input/console_input/std_console_input_handler.h"
#include "../../input/AI/std_ai.h"
#include "../../ships/std_ship/std_ship.h"

std_player_manager::std_player_manager(std::uint8_t index,
                                       std::unique_ptr<player_base> && first,
                                       std::unique_ptr<player_base> && second)
{
    this->active_player_index = index;

    players[0].player = std::move(first);
    players[0].input_handler = std::make_unique<std_console_input_handler>();
    players[1].player = std::move(second);
    players[1].input_handler = std::make_unique<std_ai>(players[0].player->get_field_view());

    players[0].player->place_ship(std::make_shared<std_ship>(3), {{9,5},{9,7}});
    players[0].player->place_ship(std::make_shared<std_ship>(3), {{9,0},{9,2}});
    players[0].player->place_ship(std::make_shared<std_ship>(2), {{6,1},{7,1}});
    players[0].player->place_ship(std::make_shared<std_ship>(2), {{4,6},{4,7}});
    players[0].player->place_ship(std::make_shared<std_ship>(2), {{1,8},{1,9}});
    players[0].player->place_ship(std::make_shared<std_ship>(1), {{3,0},{3,0}});
    players[0].player->place_ship(std::make_shared<std_ship>(1), {{4,3},{4,3}});
    players[0].player->place_ship(std::make_shared<std_ship>(1), {{7,6},{7,6}});
    players[0].player->place_ship(std::make_shared<std_ship>(1), {{6,9},{6,9}});

    players[1].player->place_ship(std::make_shared<std_ship>(4), {{1,1},{1,4}});
    players[1].player->place_ship(std::make_shared<std_ship>(3), {{8,5},{8,7}});
    players[1].player->place_ship(std::make_shared<std_ship>(3), {{9,0},{9,2}});
    players[1].player->place_ship(std::make_shared<std_ship>(2), {{6,1},{7,1}});
    players[1].player->place_ship(std::make_shared<std_ship>(2), {{4,6},{4,7}});
    players[1].player->place_ship(std::make_shared<std_ship>(2), {{1,8},{1,9}});
    players[1].player->place_ship(std::make_shared<std_ship>(1), {{3,0},{3,0}});
    players[1].player->place_ship(std::make_shared<std_ship>(1), {{4,3},{4,3}});
    players[1].player->place_ship(std::make_shared<std_ship>(1), {{6,6},{6,6}});
    players[1].player->place_ship(std::make_shared<std_ship>(1), {{6,9},{6,9}});
}

user & std_player_manager::get_user_impl(std::size_t index)
{
    if (index >= players.size())
        return players[0];

    return players[index];
}

void std_player_manager::turn_impl()
{
    active_player_index == 1 ? active_player_index = 0 : ++active_player_index;
}

user & std_player_manager::get_active_impl()
{
    return players[active_player_index];
}

user & std_player_manager::get_inactive_impl()
{
    return active_player_index == 0 ? players[1] : players[0];
}