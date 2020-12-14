//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player_base.h"

std::unique_ptr<renderable_message> ext_player_base::get_render_info() const
{
    return get_render_info_impl();
}

bool ext_player_base::has_duty() const
{
    return has_duty_impl();
}

void ext_player_base::fulfill_duty(const coordinate_2d<std::size_t> & point)
{
    fulfill_duty_impl(point);
}

bool ext_player_base::reveal_self_ship(const coordinate_2d<std::size_t> & point)
{
    return reveal_self_ship_impl(point);
}

bool ext_player_base::kill_self(const coordinate_2d<std::size_t> & point)
{
    return kill_self_impl(point);
}