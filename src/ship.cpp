//
// Created by spector on 9/17/20.
//

#include "ship.h"

void ship::reduce_size()
{
    destroyed = --_size;
}

bool ship::is_destroyed() const
{
    return destroyed;
}

std::size_t ship::size() const
{
    return _size;
}

[[nodiscard]] std::function<void()> ship::on_destroy() const
{
    return on_destroy_iml();
}