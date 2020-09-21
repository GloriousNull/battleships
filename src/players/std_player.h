//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_STD_PLAYER_H
#define BATTLESHIPS_STD_PLAYER_H

#include "std_player_base.h"

class std_player final : public std_player_base
{
private:
    [[nodiscard]] bool attack_impl(std_player_base *, const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) override;
};

#endif //BATTLESHIPS_STD_PLAYER_H