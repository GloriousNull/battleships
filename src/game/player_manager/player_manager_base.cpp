//
// Created by GloriousSir on 10/31/2020.
//

#include "player_manager_base.h"

user & player_manager_base::get_user(std::size_t index)
{
    return get_user_impl(index);
}

user & player_manager_base::get_active()
{
    return get_active_impl();
}

user & player_manager_base::get_inactive()
{
    return get_inactive_impl();
}

void player_manager_base::turn()
{
    turn_impl();
}