//
// Created by GloriousSir on 10/10/2020.
//

#include "std_game.h"
#include "../players/std_player.h"

std_game::std_game()
{
    this->player_0 = std::make_unique<std_player>();
    this->player_1 = std::make_unique<std_player>();

    this->running = false;
}