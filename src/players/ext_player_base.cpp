//
// Created by GloriousSir on 9/21/2020.
//

#include "ext_player_base.h"

duty ext_player_base::get_duty_impl() const
{
    return _duty;
}

void ext_player_base::set_duty(duty duty_to_set)
{
    set_duty_impl(duty_to_set);
}


duty ext_player_base::get_duty() const
{
    return get_duty_impl();
}

void ext_player_base::set_duty_impl(duty duty_to_set)
{
    _duty = duty_to_set;
}

bool ext_player_base::reveal_self(const coordinate_2d<std::size_t> & point)
{
    return reveal_self_impl(point);
}

bool ext_player_base::kill_self(const coordinate_2d<std::size_t> & point)
{
    return kill_self_impl(point);
}