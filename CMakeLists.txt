cmake_minimum_required(VERSION 3.16)
project(src/battlefields)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")

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

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    set(PROJECT_WARNINGS ${CLANG_WARNINGS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PROJECT_WARNINGS ${GCC_WARNINGS})
else()
    message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(Soci REQUIRED)

find_package(Threads)

add_executable(
        battlefields main.cpp src/battlefields/std_battlefield.h src/players/std_player/std_player.h src/ships/ship_base.cpp
        src/ships/ship_base.h src/config.h src/utils/math/coordinate_2d.h src/utils/math/segment.h
        src/utils/math/non_inclined_segment.h src/battlefields/std_battlefield.cpp src/players/std_player/std_player.cpp
        src/players/player_base.cpp src/players/player_base.h src/players/ext_player/ext_player_base.cpp
        src/players/ext_player/ext_player_base.h src/players/ext_player/ext_player.cpp
        src/players/ext_player/ext_player.h src/battlefields/battlefield_base.cpp src/battlefields/battlefield_base.h
        src/ships/std_ship/std_ship.cpp src/ships/std_ship/std_ship.h
        src/ships/ext_ship/ext_ship_base.cpp src/ships/ext_ship/ext_ship_base.h src/utils/duty.h
        src/ships/ext_ship/ext_ship_mine.cpp src/ships/ext_ship/ext_ship_mine.h src/ships/ext_ship/ext_ship_minesweeper.cpp
        src/ships/ext_ship/ext_ship_minesweeper.h src/game/game.cpp src/game/game.h
        src/input/concurrent_input_handler_base.cpp src/input/concurrent_input_handler_base.h
        src/input/console_input/concurrent_console_input_handler.cpp src/input/console_input/concurrent_console_input_handler.h
        src/ui/user_interface_base.cpp
        src/ui/user_interface_base.h src/ui/console_user_interface.cpp src/ui/console_user_interface.h
        src/game/game_state/game_state_base.cpp src/game/game_state/game_state_base.h
        src/game/game_state/std_game_state.cpp src/game/game_state/std_game_state.h
        src/input/game_event.h src/game/player_manager/player_manager_base.cpp src/game/player_manager/player_manager_base.h
        src/game/player_manager/std_player_manager.cpp src/game/player_manager/std_player_manager.h
        src/input/input_handler_base.cpp src/input/input_handler_base.h src/input/AI/std_ai.cpp src/input/AI/std_ai.h
        src/utils/database/database.cpp src/utils/database/database.h src/game/result_manager/result_manager.cpp
        src/game/result_manager/result_manager.h src/game/result_manager/game_result.h src/game/player_manager/user.cpp
        src/game/player_manager/user.h src/std_game_config.h src/ext_game_config.h
        src/input/console_input/std_console_input_handler.cpp src/input/console_input/std_console_input_handler.h)

target_link_libraries(battlefields ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(battlefields soci_core soci_sqlite3)
include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(battlefields sqlite3)
target_compile_options(battlefields INTERFACE ${PROJECT_WARNINGS})

add_subdirectory(boost_tests)