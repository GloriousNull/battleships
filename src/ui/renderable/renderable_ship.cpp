//
// Created by GloriousSir on 12/13/2020.
//

#include "renderable_ship.h"
#include <iostream>

void renderable_ship::render_impl() const
{
    std::cout << ship;
}