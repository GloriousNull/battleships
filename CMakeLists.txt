cmake_minimum_required(VERSION 3.16)
project(src/battlefields)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CLANG_WARNINGS
        -Wall
        -Wextra # reasonable and standard
        -Wshadow # warn the user if a variable declaration shadows one from a parent context
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps
        # catch hard to track down memory errors
        -Wold-style-cast # warn for c-style casts
        -Wcast-align # warn for potential performance problem casts
        -Wunused # warn on anything being unused
        -Woverloaded-virtual # warn if you overload (not override) a virtual function
        -Wpedantic # warn if non-standard C++ is used
        -Wconversion # warn on type conversions that may lose data
        -Wsign-conversion # warn on sign conversions
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output (ie printf)
        )

set(GCC_WARNINGS
        ${CLANG_WARNINGS}
        -Wmisleading-indentation # warn if indentation implies blocks where blocks do not exist
        -Wduplicated-cond # warn if if / else chain has duplicated conditions
        -Wduplicated-branches # warn if if / else branches have duplicated code
        -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
        -Wuseless-cast # warn if you perform a cast to the same type
        )

set(CMAKE_CXX_STANDARD 20)

add_executable(
        battlefields main.cpp src/battlefields/std_battlefield.h src/players/std_player.h src/ships/std_ship_base.cpp
        src/ships/std_ship_base.h src/config.h src/utils/coordinate_2d.h src/utils/segment.h
        src/utils/non_inclined_segment.h src/battlefields/std_battlefield.cpp src/players/std_player.cpp src/players/std_player_base.cpp
        src/players/std_player_base.h src/players/ext_player_base.cpp src/players/ext_player_base.h src/players/ext_player.cpp
        src/players/ext_player.h src/battlefields/std_battlefield_base.cpp src/battlefields/std_battlefield_base.h src/ships/std_ship.cpp
        src/ships/std_ship.h src/ships/ext_ship_base.cpp src/ships/ext_ship_base.h src/utils/duty.h
        src/ships/ext_ship_mine.cpp src/ships/ext_ship_mine.h src/ships/ext_ship_minesweeper.cpp src/ships/ext_ship_minesweeper.h
        src/game/std_game_base.cpp src/game/std_game_base.h src/game/std_game.cpp src/game/std_game.h
        src/game/ext_game.cpp src/game/ext_game.h src/input/input_handler_base.cpp src/input/input_handler_base.h
        src/input/console_input_handler.cpp src/input/console_input_handler.h src/ui/user_interface_base.cpp
        src/ui/user_interface_base.h src/ui/console_user_interface.cpp src/ui/console_user_interface.h )

add_subdirectory(boost_tests)