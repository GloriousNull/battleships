//
// Created by GloriousSir on 10/31/2020.
//

#ifndef SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H
#define SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H

#include <array>

#include "user.h"

class player_manager_base
{
protected:
    std::array<user, 2> players;
    std::uint8_t active_player_index;
private:
    [[nodiscard]] virtual user & get_user_impl(std::size_t) = 0;
    [[nodiscard]] virtual user & get_active_impl() = 0;
    [[nodiscard]] virtual user & get_inactive_impl() = 0;
    virtual void turn_impl() = 0;
public:
    void start_listeners(const bool &);
    void stop_listeners();
    [[nodiscard]] user & get_user(std::size_t);
    [[nodiscard]] user & get_active();
    [[nodiscard]] user & get_inactive();
    void turn();
};


#endif //SRC_BATTLEFIELDS_PLAYER_MANAGER_BASE_H
