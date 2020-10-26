//
// Created by GloriousSir on 10/25/2020.
//

#include "user_interface_base.h"

void user_interface_base::update()
{
    update_impl();
}

void user_interface_base::link_game(std_game_base * game)
{
    game_to_show = game;
}
