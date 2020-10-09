//
// Created by GloriousSir on 9/21/2020.
//

#include "std_battlefield.h"

bool std_battlefield::is_all_ships_placed_impl() const
{
    return this->is_all_placed;
}

bool std_battlefield::is_enough_space_to_place(const std::size_t & ship_size, const non_inclined_segment<std::size_t, std::size_t> & segment) const
{
    if (ship_size - 1 != segment.get_length())
        return false;

    const std::size_t y_it_start = !segment.get_begin().get_y() ? 0 : segment.get_begin().get_y() - 1;
    const std::size_t x_it_start = !segment.get_begin().get_x() ? 0 : segment.get_begin().get_x() - 1;
    const std::size_t y_end = segment.get_end().get_y();
    const std::size_t x_end = segment.get_end().get_x();

    for (std::size_t y_it{y_it_start}; y_it <= y_end; ++y_it)
        for (std::size_t x_it{x_it_start}; x_it <= x_end; ++x_it)
            if (field[y_it][x_it].containable_ship)
                return false;

    return true;
}

bool std_battlefield::place_ship_impl(const std::shared_ptr<std_ship_base> & ship_ptr, const non_inclined_segment<std::size_t, std::size_t> & segment)
{
    if (!segment.is_valid() || !is_enough_space_to_place(ship_ptr->size(), segment))
    {
        return false;
    }

    std::size_t begin = segment.get_begin().get_x();
    std::size_t end = segment.get_begin().get_y();
    std::size_t & it = segment.is_horizontal() ? begin : end;
    const std::size_t & it_end = segment.is_horizontal() ? segment.get_end().get_x() : segment.get_end().get_y();

    for (; it <= it_end; ++it)
        field[begin][end].containable_ship = ship_ptr;

    this->is_all_placed = ++amount_of_ships == AMOUNT_OF_SHIPS;

    return true;
}

bool std_battlefield::remove_ship_segment_impl(const coordinate_2d<std::size_t> & point)
{
    if (field[point.get_x()][point.get_y()].containable_ship)
    {
        if (field[point.get_x()][point.get_y()].containable_ship->is_destroyed())
            --amount_of_ships;

        field[point.get_x()][point.get_y()].containable_ship = nullptr;

        return true;
    }

    return false;

}

bool std_battlefield::reveal_impl(const coordinate_2d<std::size_t> & point)
{
    if (point.get_x() < 0 || point.get_x() >= FIELD_SIZE || point.get_y() < 0 || point.get_y() >= FIELD_SIZE)
        return false;

    if (field[point.get_x()][point.get_y()].is_hidden)
    {
        field[point.get_x()][point.get_y()].is_hidden = false;

        return true;
    }

    return false;
}

std::shared_ptr<std_ship_base> std_battlefield::get_ship_impl(const coordinate_2d<std::size_t> & point)
{
    return field[point.get_x()][point.get_y()].containable_ship;
}