//
// Created by spector on 9/17/20.
//

#include "std_ship_base.h"

void std_ship_base::reduce_size()
{
    --_size;
}

bool std_ship_base::is_destroyed() const
{
    return !_size;
}

std::size_t std_ship_base::size() const
{
    return _size;
}