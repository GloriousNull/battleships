//
// Created by GloriousSir on 12/12/2020.
//

#include "action_state_base.h"

void action_state_base::initialize(std::size_t active_player_index,
                                   user<player_base> & player,
                                   user<player_base> & enemy)
{
    initialize_impl(active_player_index,player, enemy);
}

result_manager & action_state_base::get_result_manager()
{
    return res_manager;
}