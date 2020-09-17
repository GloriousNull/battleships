cmake_minimum_required(VERSION 3.17)
project(battleships)

set(CMAKE_CXX_STANDARD 20)

add_executable(battleships main.cpp battle_field.h player.cpp player.h ship.cpp ship.h config.h ships/battle_ship.cpp ships/battle_ship.h ships/surprise_ship.cpp ships/surprise_ship.h ships/unsurprising_ship.cpp ships/unsurprising_ship.h utils/coordinate_2d.h)