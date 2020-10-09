//
// Created by GloriousSir on 10/6/2020.
//

#include "std_ship.h"

std_ship::std_ship(const std::size_t & size)
{
    this->_size = size;
}

bool std_ship::is_destroyed_impl() const
{
    return !this->_size;
}

void std_ship::apply_damage_impl()
{
    --this->_size;
}