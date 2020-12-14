//
// Created by GloriousSir on 10/29/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_GAME_STATE_H
#define SRC_BATTLEFIELDS_STD_GAME_STATE_H


#include "action_state_base.h"
#include "../../input/game_event.h"
#include "../player_manager/player_manager.h"

class std_game_state final : public action_state_base
{
private:
    player_manager<player_base> _player_manager;

    void initialize_impl(std::size_t, user<player_base> &, user<player_base> &) override;
    const std::vector<renderable_ptr> get_render_info_impl() const override;
    bool process_input_impl() override;

    void handle_ship_placement(const game_event &);
    bool handle_attack(const game_event &);
public:
    std_game_state();
};


#endif //SRC_BATTLEFIELDS_STD_GAME_STATE_H
