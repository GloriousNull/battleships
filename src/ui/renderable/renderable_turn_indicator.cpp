//
// Created by GloriousSir on 12/11/2020.
//

#include <iostream>

#include "renderable_turn_indicator.h"

void renderable_turn_indicator::render_impl() const
{
    if (!id)
        std::cout << "Your turn:\n";
    else
        std::cout << "Enemy turn:\n";
}