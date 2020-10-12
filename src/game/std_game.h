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
    void run_impl() override;

    [[nodiscard]] bool preparation_phase();
    [[nodiscard]] bool main_loop();
public:
    std_game();
};


#endif //BATTLEFIELDS_STD_GAME_H
