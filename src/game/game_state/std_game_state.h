//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_GAME_STATE_H
#define SRC_BATTLEFIELDS_STD_GAME_STATE_H

#include "game_state_base.h"

class player_base;

class std_game_state final : public game_state_base
{
private:
    std::tuple<std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>,
    std::span<const std::array<battlefield_base::point_info, FIELD_SIZE>, FIELD_SIZE>>
    get_render_info_impl() const override;
    bool process_input_impl() override;

    void handle_nick_change(const game_event &);
    void handle_ship_placement(const game_event &);
    void handle_attack(const game_event &);
public:
    std_game_state();
};


#endif //SRC_BATTLEFIELDS_STD_GAME_STATE_H
