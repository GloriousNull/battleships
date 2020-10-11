//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player_base.h"

bool std_player_base::is_ready() const
{
    return is_ready_impl();
}

std::tuple<bool, bool> std_player_base::attack(const std::shared_ptr<std_player_base> & player, const coordinate_2d<std::size_t> & point)
{
    return attack_impl(player, point);
}
