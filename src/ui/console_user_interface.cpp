//
// Created by GloriousSir on 10/25/2020.
//

#include "console_user_interface.h"

void console_user_interface::render_impl(const std::unique_ptr<game_state_base> & state)
{
    if (state && !state->changed())
        return;

    auto to_render = state->get_render_info();

    if (to_render)
        to_render->render();
}