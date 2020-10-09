//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player_base.h"

bool ext_player_base::reveal_self(const coordinate_2d<std::size_t> & point)
{
    return reveal_self_impl(point);
}

bool ext_player_base::kill_self(const coordinate_2d<std::size_t> & point)
{
    return kill_self_impl(point);
}