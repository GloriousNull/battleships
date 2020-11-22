//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_CONFIG_H
#define BATTLESHIPS_CONFIG_H

    using ULL = unsigned long long;

    inline constexpr ULL AMOUNT_OF_BATTLE_SHIPS{3};
    inline constexpr ULL AMOUNT_OF_SURPRISE_SHIPS{3};
    inline constexpr ULL AMOUNT_OF_UNSURPRISING_SHIPS{2};

    inline constexpr ULL FIELD_SIZE{10};
    inline constexpr ULL AMOUNT_OF_SHIPS = AMOUNT_OF_BATTLE_SHIPS+AMOUNT_OF_SURPRISE_SHIPS+AMOUNT_OF_UNSURPRISING_SHIPS;

#endif //BATTLESHIPS_CONFIG_H
