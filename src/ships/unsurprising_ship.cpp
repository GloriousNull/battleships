//
// Created by spector on 9/17/20.
//

#include "unsurprising_ship.h"


unsurprising_ship::unsurprising_ship()
{
    _size = 1;
}

std::function<void()> unsurprising_ship::on_destroy_iml() const
{
    //TODO
    return [](){};
}