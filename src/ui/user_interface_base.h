//
// Created by GloriousSir on 10/25/2020.
//

#ifndef SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H
#define SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H

#include "../game/std_game_base.h"

class std_game_base;

class user_interface_base
{
protected:
    std_game_base * game_to_show;
private:
    virtual void update_impl() = 0;
public:
    void link_game(std_game_base *);
    virtual ~user_interface_base() = default;

    void update();
};


#endif //SRC_BATTLEFIELDS_USER_INTERFACE_BASE_H
