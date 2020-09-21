//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_EXT_PLAYER_BASE_H
#define BATTLESHIPS_EXT_PLAYER_BASE_H

#include "std_player_base.h"
#include "../duty.h"

class ext_player_base : public std_player_base
{
protected:
    duty _duty{duty::none};
private:
    [[nodiscard]] virtual bool reveal_self_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool kill_self_impl(const coordinate_2d<std::size_t> &) = 0;
public:
    [[nodiscard]] duty get_duty() const;
    void set_duty(duty);
    [[nodiscard]] bool reveal_self(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool kill_self(const coordinate_2d<std::size_t> &);
};


#endif //BATTLESHIPS_EXT_PLAYER_BASE_H
