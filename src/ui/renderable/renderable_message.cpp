//
// Created by GloriousSir on 12/13/2020.
//

#include "renderable_message.h"
#include <iostream>

void renderable_message::render_impl() const
{
    std::cout << duty_to_render << '\n';
}