enable_testing()

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (boost_tests_run
        ship_tests/std_ship_tests.cpp ship_tests/ext_ship_mine_tests.cpp
        utils_tests/coordinate_2d_test.cpp utils_tests/segment_tests.cpp utils_tests/non_inclined_segment_tests.cpp utils_tests/duty_tests.cpp
        battlefields_tests/std_battlefield_tests.cpp
        player_tests/std_player_tests.cpp  player_tests/ext_player_tests.cpp

        ../src/battlefields/std_battlefield.h ../src/players/std_player.h ../src/ships/std_ship_base.cpp ../src/ships/std_ship_base.h
        ../src/config.h ../src/utils/coordinate_2d.h ../src/utils/segment.h ../src/utils/non_inclined_segment.h ../src/battlefields/std_battlefield.cpp
        ../src/players/std_player.cpp ../src/players/std_player_base.cpp ../src/players/std_player_base.h ../src/players/ext_player_base.cpp
        ../src/players/ext_player_base.h ../src/players/ext_player.cpp ../src/players/ext_player.h ../src/battlefields/std_battlefield_base.cpp
        ../src/battlefields/std_battlefield_base.h ../src/ships/std_ship.cpp ../src/ships/std_ship.h ../src/ships/ext_ship_base.cpp
        ../src/ships/ext_ship_base.h ../src/utils/duty.h ../src/ships/ext_ship_mine.cpp ../src/ships/ext_ship_mine.h ../src/ships/ext_ship_minesweeper.cpp
        ../src/ships/ext_ship_minesweeper.h ../src/game/std_game_base.cpp ../src/game/std_game_base.h ../src/game/std_game.cpp ../src/game/std_game.h
        ../src/game/ext_game.cpp ../src/game/ext_game.h utils_tests/coordinate_2d_test.cpp utils_tests/segment_tests.cpp utils_tests/non_inclined_segment_tests.cpp utils_tests/duty_tests.cpp ship_tests/ext_ship_mine_tests.cpp ship_tests/ext_ship_minesweeper_tests.cpp battlefields_tests/std_battlefield_tests.cpp player_tests/std_player_tests.cpp player_tests/ext_player_tests.cpp)
target_link_libraries (boost_tests_run ${Boost_LIBRARIES})