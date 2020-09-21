//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_STD_PLAYER_BASE_H
#define BATTLESHIPS_STD_PLAYER_BASE_H

#include <memory>

#include "../ships/std_ship_base.h"
#include "../utils/non_inclined_segment.h"
#include "../battle_field.h"

class std_player_base
{
protected:
    battle_field field{};
private:
    [[nodiscard]] virtual bool attack_impl(std_player_base *, const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool place_ship_impl(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) = 0;
public:
    virtual ~std_player_base() = default;

    [[nodiscard]] bool attack(std_player_base *, const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool place_ship(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &);
    [[nodiscard]] battle_field & get_field();
};

#endif //BATTLESHIPS_STD_PLAYER_BASE_H
