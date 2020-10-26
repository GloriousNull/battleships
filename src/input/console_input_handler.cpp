//
// Created by spector on 10/19/20.
//

#include "console_input_handler.h"

#include "../ships/std_ship.h"
#include "../ships/ext_ship_mine.h"
#include "../ships/ext_ship_minesweeper.h"

std::shared_ptr<std_ship_base> console_input_handler::get_ship_impl(const std::size_t & size)
{
    char choice;

    std::cin >> choice;

    switch (choice)
    {
        case 's':
            return std::make_shared<std_ship>(size);

        case 'm':
            return std::make_shared<ext_ship_mine>(1);

        case 'r':
            return std::make_shared<ext_ship_minesweeper>(1);

        default:
            return nullptr;
    }
}

coordinate_2d<std::size_t> console_input_handler::get_coordinate_impl()
{
    coordinate_2d<std::size_t> coor;

    std::cin >> coor;

    return coor;
}