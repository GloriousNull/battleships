//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_CONFIG_H
#define BATTLESHIPS_CONFIG_H

    inline constexpr unsigned long long AMOUNT_OF_BATTLE_SHIPS{3};
    inline constexpr unsigned long long AMOUNT_OF_SURPRISE_SHIPS{3};
    inline constexpr unsigned long long AMOUNT_OF_UNSURPRISING_SHIPS{2};

    inline constexpr unsigned long long FIELD_SIZE{10};
    inline constexpr unsigned long long AMOUNT_OF_SHIPS = AMOUNT_OF_BATTLE_SHIPS+AMOUNT_OF_SURPRISE_SHIPS+AMOUNT_OF_UNSURPRISING_SHIPS;

    inline constexpr unsigned long long STD_MAX_SHIP_LENGTH{2};
    inline constexpr unsigned long long STD_STARTER_AMOUNT_OF_SHIPS{1};
#endif //BATTLESHIPS_CONFIG_H
