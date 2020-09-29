//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_STD_PLAYER_BASE_H
#define BATTLESHIPS_STD_PLAYER_BASE_H

#include <memory>

#include "../ships/std_ship_base.h"
#include "../utils/non_inclined_segment.h"
#include "../battlefields/std_battlefield.h"

class std_player_base
{
protected:
    std::unique_ptr<std_battlefield_base> field;
private:
    [[nodiscard]] virtual std::tuple<bool, bool> attack_impl(const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool place_ship_impl(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) = 0;
public:
    virtual ~std_player_base() = default;

    [[nodiscard]] std::tuple<bool, bool> attack(const std::shared_ptr<std_player_base> &, const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool place_ship(const std::shared_ptr<std_ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &);
};

#endif //BATTLESHIPS_STD_PLAYER_BASE_H
