//
// Created by GloriousSir on 10/6/2020.
//

#include "std_ship.h"

std_ship::std_ship(const std::size_t & size)
{
    this->_size = size;
    this->_durability = size;
}

bool std_ship::is_destroyed_impl() const
{
    return !this->_durability;
}

std::unique_ptr<renderable_ship> std_ship::get_render_info_impl() const
{
    return std::make_unique<renderable_ship>('b');
}

void std_ship::apply_damage_impl()
{
    --this->_durability;
}