//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_STD_PLAYER_H
#define BATTLESHIPS_STD_PLAYER_H

#include "../player_base.h"

class std_player final : public player_base
{
private:
    [[nodiscard]] std::size_t amount_of_owned_ships_impl() const override;
    [[nodiscard]] bool is_ready_impl() const override;
    [[nodiscard]] std::tuple<bool, bool> attack_impl(std::unique_ptr<player_base> &, const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) override;
public:
    std_player();
};

#endif //BATTLESHIPS_STD_PLAYER_H
