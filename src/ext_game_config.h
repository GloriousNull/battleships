//
// Created by GloriousSir on 11/21/2020.
//

#ifndef SRC_BATTLEFIELDS_EXT_GAME_CONFIG_H
#define SRC_BATTLEFIELDS_EXT_GAME_CONFIG_H

#include <array>

using ULL = unsigned long long;

inline constexpr ULL EXT_MAX_SHIP_LENGTH{4};
inline constexpr ULL EXT_FIELD_SIZE{10};

constexpr std::array<ULL, 4> EXT_MAX_DECKS = {1,2,3,4};

#endif //SRC_BATTLEFIELDS_EXT_GAME_CONFIG_H
