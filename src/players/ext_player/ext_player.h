//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_EXT_PLAYER_H
#define BATTLESHIPS_EXT_PLAYER_H

#include "ext_player_base.h"

class ext_player final : public ext_player_base, public std::enable_shared_from_this<ext_player_base>
{
private:
    std::unique_ptr<renderable_message> get_render_info_impl() const override;
    [[nodiscard]] bool has_duty_impl() const override;
    void fulfill_duty_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool reveal_self_ship_impl(const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool kill_self_impl(const coordinate_2d<std::size_t> &) override;

    [[nodiscard]] bool is_ready_impl() const override;
    [[nodiscard]] std::size_t amount_of_owned_ships_impl() const override;
    [[nodiscard]] std::tuple<bool, bool> attack_impl(std::unique_ptr<player_base> &, const coordinate_2d<std::size_t> &) override;
    [[nodiscard]] bool place_ship_impl(const std::shared_ptr<ship_base> &, const non_inclined_segment<std::size_t,std::size_t> &) override;
public:
    ext_player();
};


#endif //BATTLESHIPS_EXT_PLAYER_H
