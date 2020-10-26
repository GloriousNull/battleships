//
// Created by GloriousSir on 10/25/2020.
//

#ifndef SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H
#define SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H

#include "user_interface_base.h"

class console_user_interface final : public user_interface_base
{
private:
    void update_impl() override;
};


#endif //SRC_BATTLEFIELDS_CONSOLE_USER_INTERFACE_H
