//
// Created by spector on 9/17/20.
//

#include "battle_ship.h"

battle_ship::battle_ship(const std::size_t & size)
{
    _size = size;
}

std::function<void()> battle_ship::on_destroy_iml() const
{
    //TODO
    return [](){};
}