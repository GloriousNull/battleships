//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_FIELD_H
#define BATTLESHIPS_BATTLE_FIELD_H

#include "battlefield_base.h"

class std_battlefield final : public battlefield_base
{
private:
    void reveal_area_around_ship(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool is_enough_space_to_place(const std::size_t &, const non_inclined_segment<std::size_t, std::size_t> &) const;

    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<ship_base> &, const non_inclined_segment<std::size_t, std::size_t> &) override;
    bool remove_ship_segment_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool reveal_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] std::shared_ptr<ship_base> get_ship_impl(const coordinate_2d<std::size_t> &) override;
};

#endif //BATTLESHIPS_BATTLE_FIELD_H
