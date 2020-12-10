//
// Created by GloriousSir on 9/21/2020.
//

#ifndef BATTLESHIPS_EXT_PLAYER_BASE_H
#define BATTLESHIPS_EXT_PLAYER_BASE_H

#include "../player_base.h"
#include "../../utils/duty.h"

class ext_player_base : public player_base
{
protected:
    std::unique_ptr<duty<ext_player_base &, const coordinate_2d<std::size_t> &>> _duty;
private:
    [[nodiscard]] virtual bool has_duty_impl() const = 0;
    virtual void fulfill_duty_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool reveal_self_ship_impl(const coordinate_2d<std::size_t> &) = 0;
    [[nodiscard]] virtual bool kill_self_impl(const coordinate_2d<std::size_t> &) = 0;
public:
    [[nodiscard]] bool has_duty() const;
    void fulfill_duty(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool reveal_self_ship(const coordinate_2d<std::size_t> &);
    [[nodiscard]] bool kill_self(const coordinate_2d<std::size_t> &);
};


#endif //BATTLESHIPS_EXT_PLAYER_BASE_H