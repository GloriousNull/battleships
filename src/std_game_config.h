//
// Created by GloriousSir on 11/21/2020.
//

#ifndef SRC_BATTLEFIELDS_STD_GAME_CONFIG_H
#define SRC_BATTLEFIELDS_STD_GAME_CONFIG_H

#include <array>

using ULL = unsigned long long;

inline constexpr ULL STD_MAX_SHIP_LENGTH{4};
inline constexpr ULL STD_FIELD_SIZE{10};

constexpr std::array<ULL, 4> STD_MAX_DECKS = {4,3,2,1};

#endif //SRC_BATTLEFIELDS_STD_GAME_CONFIG_H
