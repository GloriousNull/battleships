//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/utils/segment.h"

BOOST_AUTO_TEST_SUITE(segment_test)

    BOOST_AUTO_TEST_CASE(getters)
    {
        constexpr std::int64_t x{4}, y{2};

        segment<std::int64_t, std::int64_t> seg_to_test({x,y}, {x,y});

        BOOST_CHECK(seg_to_test.get_begin().get_x() == x && seg_to_test.get_begin().get_y() == y);
        BOOST_CHECK(seg_to_test.get_end().get_x() == x && seg_to_test.get_end().get_y() == y);
        BOOST_CHECK(seg_to_test.get_length() == 0);
    }

    BOOST_AUTO_TEST_CASE(setters)
    {
        constexpr std::int64_t x{4}, y{2};

        segment<std::int64_t, std::int64_t> seg_to_test({0,4}, {5,1});
        seg_to_test.set_begin({x,y});
        seg_to_test.set_end({x,y});

        BOOST_CHECK(seg_to_test.get_begin().get_x() == x && seg_to_test.get_begin().get_y() == y);
        BOOST_CHECK(seg_to_test.get_end().get_x() == x && seg_to_test.get_end().get_y() == y);
        BOOST_CHECK(seg_to_test.get_length() == 0);
    }

BOOST_AUTO_TEST_SUITE_END()
