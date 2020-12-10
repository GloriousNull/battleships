//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_GAME_STATE_H
#define SRC_BATTLEFIELDS_STD_GAME_STATE_H

#include "../result_manager/result_manager.h"
#include "game_state_base.h"

class player_base;

class std_game_state final : public game_state_base
{
private:
    result_manager res_manager{};

    std::unique_ptr<renderable_base> get_render_info_impl() const override;
    bool process_input_impl() override;

    void handle_ship_placement(const game_event &);
    void handle_attack(const game_event &);
public:
    std_game_state();
    explicit std_game_state(std::unique_ptr<player_manager_base>);
};


#endif //SRC_BATTLEFIELDS_STD_GAME_STATE_H
