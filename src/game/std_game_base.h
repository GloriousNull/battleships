//
// Created by GloriousSir on 10/9/2020.
//

#ifndef BATTLEFIELDS_STD_GAME_BASE_H
#define BATTLEFIELDS_STD_GAME_BASE_H

#include <memory>
#include "../players/std_player_base.h"

class std_game_base
{
protected:
    std::unique_ptr<std_player_base> player_0, player_1;
    bool running;
private:

public:
    void run();
};


#endif //BATTLEFIELDS_STD_GAME_BASE_H
