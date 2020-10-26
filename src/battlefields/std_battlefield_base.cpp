//
// Created by spector on 9/23/20.
//

#include "std_battlefield_base.h"

std::size_t std_battlefield_base::current_ships() const
{
    return current_ships_impl();
}

bool std_battlefield_base::place_ship(const std::shared_ptr<std_ship_base> & ship_to_place,
                                      const non_inclined_segment<std::size_t, std::size_t> & segment)
{
    return place_ship_impl(ship_to_place, segment);
}

bool std_battlefield_base::remove_ship_segment(const coordinate_2d<std::size_t> & point)
{
    return remove_ship_segment_impl(point);
}

bool std_battlefield_base::reveal(const coordinate_2d<std::size_t> & point)
{
    return reveal_impl(point);
}

std::shared_ptr<std_ship_base> std_battlefield_base::get_ship(const coordinate_2d<std::size_t> & point)
{
    return get_ship_impl(point);
}

std::span<const std::array<std_battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE> std_battlefield_base::get_field_view() const
{
    return std::span{field};
}