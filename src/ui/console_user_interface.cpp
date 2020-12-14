//
// Created by GloriousSir on 10/25/2020.
//

#include "console_user_interface.h"

void console_user_interface::render_impl(const std::unique_ptr<game_state_base> & state)
{
    auto to_render = state->get_render_info();

    for (const auto & renderable : to_render)
        renderable->render();
}