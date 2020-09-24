cmake_minimum_required(VERSION 3.16)
project(battlefields)

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

add_executable(battlefields main.cpp battlefields/std_battlefield.h players/std_player.h ships/std_ship_base.cpp ships/std_ship_base.h config.h utils/coordinate_2d.h utils/segment.h utils/non_inclined_segment.h battlefields/std_battlefield.cpp players/std_player.cpp players/std_player_base.cpp players/std_player_base.h duty.h players/ext_player_base.cpp players/ext_player_base.h players/ext_player.cpp players/ext_player.h ships/typed_ship_base.cpp ships/typed_ship_base.h battlefields/std_battlefield_base.cpp battlefields/std_battlefield_base.h)