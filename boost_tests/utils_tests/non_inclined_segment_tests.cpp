//
// Created by GloriousSir on 10/13/2020.
//

#include <boost/test/unit_test.hpp>

#include "../../src/utils/non_inclined_segment.h"

BOOST_AUTO_TEST_SUITE(non_inclined_segment_test)

    BOOST_AUTO_TEST_CASE(valid)
    {
        constexpr std::int64_t x{4}, y{2};

        non_inclined_segment<std::int64_t, std::int64_t> seg_to_test({x,y}, {x,y});

        BOOST_CHECK(seg_to_test.is_valid());
    }

    BOOST_AUTO_TEST_CASE(not_valid)
    {
        constexpr std::int64_t x_0{0}, y_0{4}, x_1{5}, y_1{1};

        non_inclined_segment<std::int64_t, std::int64_t> seg_to_test({x_0,y_0}, {x_1,y_1});

        BOOST_CHECK(!seg_to_test.is_valid());
    }

    BOOST_AUTO_TEST_CASE(horizontal)
    {
        constexpr std::int64_t x{4}, y{2};

        non_inclined_segment<std::int64_t, std::int64_t> seg_to_test({x,y}, {x+1,y});

        BOOST_CHECK(seg_to_test.is_horizontal());
    }

    BOOST_AUTO_TEST_CASE(not_horizontal)
    {
        constexpr std::int64_t x{4}, y{2};

        non_inclined_segment<std::int64_t, std::int64_t> seg_to_test({x,y}, {x,y+1});

        BOOST_CHECK(!seg_to_test.is_horizontal());
    }

BOOST_AUTO_TEST_SUITE_END()
