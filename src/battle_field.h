//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include <vector>
#include <array>
#include <memory>

#include "config.h"
#include "ships/std_ship_base.h"
#include "utils/non_inclined_segment.h"

class battle_field
{
private:
    struct point_info
    {
        bool is_hidden{true};
        std::shared_ptr<std_ship_base> containable_ship{nullptr};
    };

    std::vector<std::shared_ptr<std_ship_base>> ships;
    std::array<std::array<point_info, FIELD_SIZE>, FIELD_SIZE> field{};

    [[nodiscard]] bool is_enough_space_to_place(const std::size_t &, const non_inclined_segment<std::size_t, std::size_t> &) const;
public:
    battle_field();
    [[nodiscard]] bool is_all_ships_placed() const;
    [[nodiscard]] bool place_ship(const std::shared_ptr<std_ship_base>&, const non_inclined_segment<std::size_t, std::size_t> &);
    [[nodiscard]] bool reveal(const coordinate_2d<std::size_t> &);
    [[nodiscard]] std::shared_ptr<std_ship_base> get_ship(const coordinate_2d<std::size_t> &);
};

#endif //BATTLESHIPS_BATTLE_FIELD_H
