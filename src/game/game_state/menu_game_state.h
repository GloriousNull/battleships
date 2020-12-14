//
// Created by GloriousSir on 12/7/2020.
//

#ifndef SRC_BATTLEFIELDS_MENU_GAME_STATE_H
#define SRC_BATTLEFIELDS_MENU_GAME_STATE_H

#include "game_state_base.h"
#include "../player_manager/player_manager.h"
#include "../../players/std_player/std_player.h"
#include "../../input/AI/std_ai.h"
#include "../../input/web_input/web_input_handler.h"
#include "../../web/message/input_message.h"
#include "spdlog/spdlog.h"

#include "../player_manager/player_manager.h"
#include "../../input/web_input/web_wrapper.h"
#include "../game_state/std_game_state.h"

class menu_game_state final : public game_state_base
{
private:
    std::string name{"Warren"};
    std::unique_ptr<std_console_input_handler> input_handler;
    std::unique_ptr<game_state_base> & next_state;

    const std::vector<renderable_ptr> get_render_info_impl() const override;
    bool process_input_impl() override;

    void handle_nick_change(const game_event &);
    bool handle_game_starting(const game_event &);
    bool handle_port_opening(game_event &);
    void initialize_web_game(ba::io_context &, const game_event &,
                             std::shared_ptr<ba::ip::tcp::socket>, std::uint8_t);
public:
    explicit menu_game_state(std::unique_ptr<game_state_base> & next)
    : next_state{next}, input_handler{std::make_unique<std_console_input_handler>()}
    {
        this->stage = game_stage::menu;
    }
};


#endif //SRC_BATTLEFIELDS_MENU_GAME_STATE_H
