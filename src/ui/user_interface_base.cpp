//
// Created by GloriousSir on 10/25/2020.
//

#include "user_interface_base.h"

void user_interface_base::render(const std::unique_ptr<game_state_base> & state)
{
    render_impl(state);
}