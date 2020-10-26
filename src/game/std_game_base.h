//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_STD_GAME_BASE_H
#define BATTLEFIELDS_STD_GAME_BASE_H

#include "../players/std_player_base.h"
#include "../input/input_handler_base.h"
#include "../ui/user_interface_base.h"

class user_interface_base;

enum class game_phase : std::int8_t
{
    preparation,
    main,
};

class std_game_base
{
protected:
    game_phase phase;
    std::unique_ptr<input_handler_base> input_handler;
    std::unique_ptr<user_interface_base> user_interface;

    std::unique_ptr<std_player_base> player_0, player_1;
    bool running;
private:
    [[nodiscard]] virtual bool is_running_impl() const = 0;
    [[nodiscard]] virtual const std::unique_ptr<std_player_base> & get_active_player_impl() const = 0;
    virtual void run_impl() = 0;
public:
    virtual ~std_game_base() = default;

    [[nodiscard]] bool is_running() const;
    [[nodiscard]] const std::unique_ptr<std_player_base> & get_active_player() const;
    void run();
};


#endif //BATTLEFIELDS_STD_GAME_BASE_H
