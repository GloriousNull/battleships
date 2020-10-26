//
// Created by GloriousSir on 9/21/2020.
//

#include "std_player_base.h"

bool std_player_base::is_ready() const
{
    return is_ready_impl();
}

std::size_t std_player_base::amount_of_owned_ships() const
{
    return amount_of_owned_ships_impl();
}

std::tuple<bool, bool> std_player_base::attack(std::unique_ptr<std_player_base> & player, const coordinate_2d<std::size_t> & point)
{
    return attack_impl(player, point);
}

bool std_player_base::place_ship(const std::shared_ptr<std_ship_base> & ship_to_place,
                                 const non_inclined_segment<std::size_t, std::size_t> & seg)
{
    return place_ship_impl(ship_to_place, seg);
}

std::span<const std::array<std_battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE> std_player_base::get_field_view() const
{
    return field.get()->get_field_view();
}
