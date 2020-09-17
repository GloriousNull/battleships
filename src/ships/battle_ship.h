//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_BATTLE_SHIP_H
#define BATTLESHIPS_BATTLE_SHIP_H

#include "../ship.h"

class battle_ship final : public ship
{
private:
    [[nodiscard]] std::function<void()> on_destroy_iml() const override;
public:
    explicit battle_ship(const std::size_t & _size);
};


#endif //BATTLESHIPS_BATTLE_SHIP_H
