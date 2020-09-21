//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_EXT_PLAYER_H
#define BATTLESHIPS_EXT_PLAYER_H

#include "ext_player_base.h"

class ext_player final : public ext_player_base
{
private:
    [[nodiscard]] bool reveal_self_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool kill_self_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool attack_impl(std_player_base *, const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) override;
};


#endif //BATTLESHIPS_EXT_PLAYER_H
