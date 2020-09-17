//
// Created by spector on 9/17/20.
//

#include "surprise_ship.h"

surprise_ship::surprise_ship()
{
    _size = 1;
}

std::function<void()> surprise_ship::on_destroy_iml() const
{
    //TODO
    return [](){};
}