enable_testing()

set (Boost_USE_STATIC_LIBS OFF)
find_package(Threads)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (boost_tests_run
        ship_tests/std_ship_tests.cpp ship_tests/ext_ship_mine_tests.cpp
        utils_tests/coordinate_2d_tests.cpp utils_tests/segment_tests.cpp utils_tests/non_inclined_segment_tests.cpp utils_tests/duty_tests.cpp
        battlefields_tests/std_battlefield_tests.cpp
        player_tests/std_player_tests.cpp  player_tests/ext_player_tests.cpp result_manager_tests/result_manager_tests.cpp

        ../src/utils/database/database.h ../src/utils/database/database.cpp
        ../src/battlefields/std_battlefield.h ../src/players/std_player/std_player.h ../src/ships/ship_base.cpp ../src/ships/ship_base.h
        ../src/config.h ../src/utils/math/coordinate_2d.h ../src/utils/math/segment.h ../src/utils/math/non_inclined_segment.h
        ../src/battlefields/std_battlefield.cpp ../src/players/std_player/std_player.cpp ../src/players/player_base.cpp
        ../src/players/player_base.h ../src/players/ext_player/ext_player_base.cpp
        ../src/players/ext_player/ext_player_base.h ../src/players/ext_player/ext_player.cpp ../src/players/ext_player/ext_player.h
        ../src/battlefields/battlefield_base.cpp ../src/battlefields/battlefield_base.h ../src/ships/std_ship/std_ship.cpp
        ../src/ships/std_ship/std_ship.h ../src/ships/ext_ship/ext_ship_base.cpp
        ../src/ships/ext_ship/ext_ship_base.h ../src/utils/duty.h ../src/ships/ext_ship/ext_ship_mine.cpp
        ../src/ships/ext_ship/ext_ship_mine.h ../src/ships/ext_ship/ext_ship_minesweeper.cpp
        ../src/ships/ext_ship/ext_ship_minesweeper.h ../src/game/game.cpp ../src/game/game.h
        ../src/input/input_handler_base.h ../src/input/input_handler_base.cpp
        ../src/input/concurrent_input_handler_base.h ../src/input/concurrent_input_handler_base.cpp
        ../src/input/console_input/concurrent_console_input_handler.h ../src/input/console_input/concurrent_console_input_handler.cpp
        ../src/ui/user_interface_base.h ../src/ui/user_interface_base.cpp ../src/ui/console_user_interface.h
        ../src/ui/console_user_interface.cpp ../src/game/game_state/game_state_base.h ../src/game/game_state/game_state_base.cpp
        ../src/game/game_state/std_game_state.h ../src/game/game_state/std_game_state.cpp ../src/game/player_manager/player_manager_base.h
        ../src/game/player_manager/player_manager_base.cpp ../src/game/player_manager/std_player_manager.h
        ../src/game/player_manager/std_player_manager.cpp ../src/game/result_manager/result_manager.h ../src/game/result_manager/result_manager.cpp
        ../src/game/result_manager/game_result.h ../src/input/AI/std_ai.h ../src/input/AI/std_ai.cpp
        ../src/input/console_input/std_console_input_handler.h ../src/input/console_input/std_console_input_handler.cpp)

include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(boost_tests_run sqlite3)
target_link_libraries(boost_tests_run ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (boost_tests_run ${Boost_LIBRARIES})