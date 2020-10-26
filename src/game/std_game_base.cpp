//
// Created by GloriousSir on 10/9/2020.
//

#include "std_game_base.h"

bool std_game_base::is_running() const
{
    return is_running_impl();
}

void std_game_base::run()
{
    run_impl();
}

const std::unique_ptr<std_player_base> & std_game_base::get_active_player() const
{
    return get_active_player_impl();
}