//
// Created by GloriousSir on 12/12/2020.
//

#ifndef SRC_BATTLEFIELDS_EXT_GAME_STATE_H
#define SRC_BATTLEFIELDS_EXT_GAME_STATE_H

#include "action_state_base.h"
#include "../player_manager/player_manager.h"
#include "../../players/player_base.h"

class ext_game_state final : public action_state_base
{
private:
    player_manager<player_base> _player_manager;

    bool process_input_impl() override;
    const std::vector<renderable_ptr> get_render_info_impl() const override;
    void initialize_impl(std::size_t, user<player_base> &, user<player_base> &) override;

    void handle_duty_fulfillment(const game_event &);
    void handle_ship_placement(const game_event &);
    void handle_attack(const game_event &);
public:
    ext_game_state();
};


#endif //SRC_BATTLEFIELDS_EXT_GAME_STATE_H
