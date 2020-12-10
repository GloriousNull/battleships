//
// Created by GloriousSir on 12/7/2020.
//

#ifndef SRC_BATTLEFIELDS_MENU_GAME_STATE_H
#define SRC_BATTLEFIELDS_MENU_GAME_STATE_H

#include "game_state_base.h"
#include "../player_manager/std_player_manager.h"
#include "../../players/std_player/std_player.h"
#include "../../input/AI/std_ai.h"
#include "../../input/web_input/web_input_handler.h"
#include "../../web/message/std_message.h"
#include "spdlog/spdlog.h"

#include "../player_manager/std_player_manager.h"
#include "../../input/web_input/web_wrapper.h"
#include "../game_state/std_game_state.h"

class menu_game_state final : public game_state_base
{
private:
    std::unique_ptr<game_state_base> & next_state;

    std::unique_ptr<renderable_base> get_render_info_impl() const override;
    bool process_input_impl() override;

    void handle_nick_change(const game_event &);
    bool handle_enemy_setting(const game_event &);
    bool handle_port_opening(const game_event &);
    void initialize_web_game(ba::ip::tcp::socket &&, std::uint8_t);
public:
    explicit menu_game_state(std::unique_ptr<game_state_base> & next) : next_state{next}
    {
        player_manager = std::make_unique<std_player_manager>(0, std::make_unique<std_console_input_handler>());
        stage = game_stage::menu;
        _changed = false;
    }
};


#endif //SRC_BATTLEFIELDS_MENU_GAME_STATE_H
