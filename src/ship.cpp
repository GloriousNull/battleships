//
// Created by spector on 9/17/20.
//

#include "ship.h"

ship::ship(const std::size_t & size)
{
    _size = size;
    _destroyed = false;
}

void ship::reduce_size()
{
    _destroyed = --_size;
}

bool ship::is_destroyed() const
{
    return _destroyed;
}

std::size_t ship::size() const
{
    return _size;
}

[[nodiscard]] std::function<void()> ship::on_destroy() const
{
    return on_destroy_impl();
}