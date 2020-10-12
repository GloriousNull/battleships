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