//
// Created by GloriousSir on 10/31/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_PLAYER_MANAGER_H
#define SRC_BATTLEFIELDS_STD_PLAYER_MANAGER_H

#include "player_manager_base.h"

class std_player_manager final : public player_manager_base
{
private:
    user & get_user_impl(std::size_t) override;
    user & get_active_impl() override;
    user & get_inactive_impl() override;
    std::size_t get_active_id_impl() const override;
    void turn_impl() override;
public:
    explicit std_player_manager(std::uint8_t,
                                std::unique_ptr<input_handler_base> &&,
                                std::unique_ptr<input_handler_base> && second_input_handler = nullptr);
};


#endif //SRC_BATTLEFIELDS_STD_PLAYER_MANAGER_H
