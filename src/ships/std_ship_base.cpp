//
// Created by spector on 9/17/20.
//

#include "std_ship_base.h"

void std_ship_base::apply_damage()
{
    apply_damage_impl();
}

bool std_ship_base::is_destroyed() const
{
    return is_destroyed_impl();
}

std::size_t std_ship_base::size() const
{
    return _size;
}