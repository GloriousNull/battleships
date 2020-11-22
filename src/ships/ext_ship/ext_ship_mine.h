//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_EXT_SHIP_MINE_H
#define BATTLEFIELDS_EXT_SHIP_MINE_H

#include "ext_ship_base.h"

class ext_ship_mine final : public ext_ship_base
{
private:
    void apply_damage_impl() override;
    [[nodiscard]] bool is_destroyed_impl() const override;
    [[nodiscard]] duty<ext_player_base &, const coordinate_2d<std::size_t> &> on_destroy_impl() const override;
public:
    explicit ext_ship_mine(const std::size_t &);
};


#endif //BATTLEFIELDS_EXT_SHIP_MINE_H
