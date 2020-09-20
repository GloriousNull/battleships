//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_UNSURPRISING_SHIP_H
#define BATTLESHIPS_UNSURPRISING_SHIP_H

#include "../ship.h"

class unsurprising_ship : public ship
{
private:
    [[nodiscard]] std::function<void()> on_destroy_impl() const override;
public:
    explicit unsurprising_ship(const std::size_t & size) : ship(size) {}
};


#endif //BATTLESHIPS_UNSURPRISING_SHIP_H
