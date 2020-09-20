//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_SURPRISE_SHIP_H
#define BATTLESHIPS_SURPRISE_SHIP_H

#include "../ship.h"

class surprise_ship final : public ship
{
private:
    [[nodiscard]] std::function<void()> on_destroy_impl() const override;
public:
    explicit surprise_ship(const std::size_t & size) : ship(size) {}
};


#endif //BATTLESHIPS_SURPRISE_SHIP_H
