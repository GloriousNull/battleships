//
// Created by GloriousSir on 10/10/2020.
//

#ifndef BATTLEFIELDS_STD_GAME_H
#define BATTLEFIELDS_STD_GAME_H

#include "std_game_base.h"

class std_game final : public std_game_base
{
private:
    [[nodiscard]] bool is_running_impl() const override;
    [[nodiscard]] const std::unique_ptr<std_player_base> & get_active_player_impl() const override;
    void run_impl() override;

    void prepare_player(std::unique_ptr<std_player_base> &);
    void main_loop();
public:
    std_game(std::unique_ptr<input_handler_base> &&, std::unique_ptr<user_interface_base> &&);
};


#endif //BATTLEFIELDS_STD_GAME_H
