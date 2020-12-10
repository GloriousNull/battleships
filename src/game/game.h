//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_STD_GAME_BASE_H
#define BATTLEFIELDS_STD_GAME_BASE_H

#include "../ui/user_interface_base.h"
#include "game_state/game_state_base.h"
#include "game_state/menu_game_state.h"

class game
{
protected:
    std::unique_ptr<user_interface_base> user_interface;
    std::unique_ptr<game_state_base> current_game_state, next_state;

    bool running;
public:
    game(std::unique_ptr<user_interface_base> && ui)
    : user_interface{std::move(ui)}, running{false}, current_game_state{std::make_unique<menu_game_state>(next_state)}
    {}
    virtual ~game() = default;

    void run();
};


#endif //BATTLEFIELDS_STD_GAME_BASE_H
