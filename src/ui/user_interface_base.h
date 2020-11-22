//
// Created by GloriousSir on 10/25/2020.
//

#ifndef SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H
#define SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H

#include "../game/game_state/game_state_base.h"


class user_interface_base
{
private:
    virtual void render_impl(const std::unique_ptr<game_state_base> &) = 0;
public:
    void render(const std::unique_ptr<game_state_base> &);
};


#endif //SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H
