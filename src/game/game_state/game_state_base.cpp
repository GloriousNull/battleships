//
// Created by GloriousSir on 10/29/2020.
//

#include "game_state_base.h"

const std::vector<renderable_ptr> game_state_base::get_render_info() const
{
    return get_render_info_impl();
}

bool game_state_base::process_input()
{
    return process_input_impl();
}
