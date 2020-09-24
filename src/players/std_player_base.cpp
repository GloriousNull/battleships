//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player_base.h"

std::tuple<bool, bool> std_player_base::attack(const std::shared_ptr<std_player_base> & player, const coordinate_2d<std::size_t> & point)
{
    return attack_impl(player, point);
}

bool std_player_base::place_ship(const std::shared_ptr<std_ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & seg)
{
    return place_ship_impl(ship_to_place, seg);
}

std_battlefield_base & std_player_base::get_field()
{
    return get_field_impl();
}