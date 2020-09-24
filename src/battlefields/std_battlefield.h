//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include "std_battlefield_base.h"

class std_battlefield final : public std_battlefield_base
{
private:
    [[nodiscard]] bool is_enough_space_to_place(const std::size_t &, const non_inclined_segment<std::size_t, std::size_t> &) const;
    [[nodiscard]] bool is_all_ships_placed_impl() const override;
    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<std_ship_base>&, const non_inclined_segment<std::size_t, std::size_t> &) override;
    [[nodiscard]] bool reveal_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] std::shared_ptr<std_ship_base> get_ship_impl(const coordinate_2d<std::size_t> &) override;
};

#endif //BATTLESHIPS_BATTLE_FIELD_H
