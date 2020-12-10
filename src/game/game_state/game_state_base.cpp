//
// Created by GloriousSir on 10/29/2020.
//

#include "game_state_base.h"

std::unique_ptr<renderable_base> game_state_base::get_render_info() const
{
    return get_render_info_impl();
}

bool game_state_base::changed() const
{
    return changed_impl();
}

bool game_state_base::changed_impl() const
{
    return _changed;
}

bool game_state_base::process_input()
{
    return process_input_impl();
}