//
// Created by GloriousSir on 10/25/2020.
//

#ifndef SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H
#define SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H

#include "user_interface_base.h"

class console_user_interface;

class console_user_interface final : public user_interface_base
{
private:
    void render_impl(const std::unique_ptr<game_state_base> &) override;
public:
    console_user_interface()
    {
        std::cerr << "initialized\n";
    }
};


#endif //SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H
