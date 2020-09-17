//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_SURPRISE_SHIP_H
#define BATTLESHIPS_SURPRISE_SHIP_H

#include "../ship.h"

class surprise_ship final : public ship
{
private:
    [[nodiscard]] std::function<void()> on_destroy_iml() const override;
public:
    surprise_ship();
};


#endif //BATTLESHIPS_SURPRISE_SHIP_H
