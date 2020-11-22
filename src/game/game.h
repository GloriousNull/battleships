//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_STD_GAME_BASE_H
#define BATTLEFIELDS_STD_GAME_BASE_H

#include "../ui/user_interface_base.h"
#include "game_state/game_state_base.h"

class game
{
protected:
    std::unique_ptr<user_interface_base> user_interface;
    std::unique_ptr<game_state_base> game_state;

    bool running;
public:
    game(std::unique_ptr<user_interface_base> && ui, std::unique_ptr<game_state_base> && state)
    : user_interface{std::move(ui)}, game_state{std::move(state)}, running{false} {}
    virtual ~game() = default;

    void run();
};


#endif //BATTLEFIELDS_STD_GAME_BASE_H
