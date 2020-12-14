//
// Created by GloriousSir on 9/21/2020.
//

#include "std_battlefield.h"

bool std_battlefield::is_enough_space_to_place(const std::size_t & ship_size,
                                               const non_inclined_segment<std::size_t, std::size_t> & segment) const
{
    if (ship_size - 1 != segment.get_length())
        return false;

    const std::size_t x_end = segment.get_end().get_x(), y_end = segment.get_end().get_y();
    std::size_t x_it = segment.get_begin().get_x(), y_it = segment.get_begin().get_y();

    std::size_t & it = segment.is_horizontal() ? x_it : y_it;
    const std::size_t & end = segment.is_horizontal() ? x_end : y_end;

    for (; it <= end; ++it)
    {
        if (field[y_it][x_it].containable_ship
            || (y_it > 0 && field[y_it-1][x_it].containable_ship)
            || (y_it < field.size()-1 && field[y_it+1][x_it].containable_ship)
            || (x_it > 0 && field[y_it][x_it-1].containable_ship)
            || (x_it < field.size()-1 && field[y_it][x_it+1].containable_ship))
            return false;
    }

    return true;
}

bool std_battlefield::place_ship_impl(const std::shared_ptr<ship_base> & ship_ptr,
                                      const non_inclined_segment<std::size_t, std::size_t> & segment)
{
    if (!segment.is_valid() || !is_enough_space_to_place(ship_ptr->size(), segment))
        return false;

    std::size_t x_it = segment.get_begin().get_x(), y_it = segment.get_begin().get_y();
    const std::size_t x_end = segment.get_end().get_x(), y_end = segment.get_end().get_y();

    std::size_t & it = segment.is_horizontal() ? x_it : y_it;
    const std::size_t & end = segment.is_horizontal() ? x_end : y_end;

    for (; it <= end; ++it)
        field[y_it][x_it].containable_ship = ship_ptr;

    return true;
}

void std_battlefield::reveal_area_around_ship(const coordinate_2d<std::size_t> & point)
{
    std::size_t x_end_0 = point.get_x(), x_end_1 = point.get_x(),
                y_end_0 = point.get_y(), y_end_1 = point.get_y();

    for (; x_end_0 > 0; --x_end_0)
        if (!field[point.get_y()][x_end_0].containable_ship)
            break;

    for (; x_end_1 < field.size()-1; ++x_end_1)
        if (!field[point.get_y()][x_end_1].containable_ship)
            break;

    for (; y_end_0 > 0; --y_end_0)
        if (!field[y_end_0][point.get_x()].containable_ship)
            break;

    for (; y_end_1 < field.size()-1; ++y_end_1)
        if (!field[y_end_1][point.get_x()].containable_ship)
            break;

    if (x_end_1 - x_end_0 == 2 || x_end_1 - x_end_0 == 1)
    {
        for (; y_end_0 <= y_end_1; ++y_end_0)
        {
            if (!field[y_end_0][point.get_x()].containable_ship)
                field[y_end_0][point.get_x()]._status = point_info::status::open;
            if (!field[y_end_0][x_end_0].containable_ship)
                field[y_end_0][x_end_0]._status = point_info::status::open;
            if (!field[y_end_0][x_end_1].containable_ship)
                field[y_end_0][x_end_1]._status = point_info::status::open;
        }
    }
    else
    {
        for (; x_end_0 <= x_end_1; ++x_end_0)
        {
            if (!field[point.get_y()][x_end_0].containable_ship)
                field[point.get_y()][x_end_0]._status = point_info::status::open;
            if (!field[y_end_0][x_end_0].containable_ship)
                field[y_end_0][x_end_0]._status = point_info::status::open;
            if (!field[y_end_1][x_end_0].containable_ship)
                field[y_end_1][x_end_0]._status = point_info::status::open;
        }
    }
}

bool std_battlefield::remove_ship_segment_impl(const coordinate_2d<std::size_t> & point)
{
    if (field[point.get_y()][point.get_x()].containable_ship)
    {
        field[point.get_y()][point.get_x()]._status = point_info::status::burning;

        if (field[point.get_y()][point.get_x()].containable_ship->is_destroyed())
            reveal_area_around_ship(point);

        return true;
    }

    return false;
}

bool std_battlefield::reveal_impl(const coordinate_2d<std::size_t> & point)
{
    if (point.get_x() < 0 || point.get_x() >= FIELD_SIZE || point.get_y() < 0 || point.get_y() >= FIELD_SIZE)
        return false;

    if (field[point.get_y()][point.get_x()]._status == point_info::status::hidden)
    {
        field[point.get_y()][point.get_x()]._status = point_info::status::open;

        return true;
    }

    return false;
}

std::shared_ptr<ship_base> std_battlefield::get_ship_impl(const coordinate_2d<std::size_t> & point)
{
    return field[point.get_y()][point.get_x()]._status == point_info::status::burning ? nullptr
           : field[point.get_y()][point.get_x()].containable_ship;
}
