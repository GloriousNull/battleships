//
// Created by spector on 10/19/20.
//

#include "input_handler_base.h"

coordinate_2d<std::size_t> input_handler_base::get_coordinate()
{
    return get_coordinate_impl();
}

std::shared_ptr<std_ship_base> input_handler_base::get_ship(const std::size_t & size)
{
    return get_ship_impl(size);
}
