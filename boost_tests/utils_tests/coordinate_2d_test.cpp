//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/utils/coordinate_2d.h"

BOOST_AUTO_TEST_SUITE(coordinate_2d_test)

    BOOST_AUTO_TEST_CASE(getters)
    {
        constexpr std::int64_t x{4}, y{2};

        constexpr coordinate_2d<std::int64_t> coor_to_test(x,y);

        BOOST_CHECK(coor_to_test.get_x() == x);
        BOOST_CHECK(coor_to_test.get_y() == y);
    }

    BOOST_AUTO_TEST_CASE(setters)
    {
        constexpr std::int64_t x{4}, y{2};

        coordinate_2d<std::int64_t> coor_to_test;
        coor_to_test.set_x(x);
        coor_to_test.set_y(y);

        BOOST_CHECK(coor_to_test.get_x() == x);
        BOOST_CHECK(coor_to_test.get_y() == y);
    }

BOOST_AUTO_TEST_SUITE_END()
