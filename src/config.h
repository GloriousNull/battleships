//
// Created by spector on 9/17/20.
//

#ifndef BATTLESHIPS_CONFIG_H
#define BATTLESHIPS_CONFIG_H


constexpr inline unsigned long long FIELD_SIZE{10};

constexpr inline unsigned long long AMOUNT_OF_BATTLE_SHIPS{10};
constexpr inline unsigned long long AMOUNT_OF_SURPRISE_SHIPS{3};
constexpr inline unsigned long long AMOUNT_OF_UNSURPRISING_SHIPS{2};

constexpr inline unsigned long long AMOUNT_OF_SHIPS = AMOUNT_OF_BATTLE_SHIPS+AMOUNT_OF_SURPRISE_SHIPS+AMOUNT_OF_UNSURPRISING_SHIPS;

#endif //BATTLESHIPS_CONFIG_H
