//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/ships/std_ship/std_ship.h"

#include "../../src/battlefields/std_battlefield.h"

BOOST_AUTO_TEST_SUITE(std_battlefield_test)

    BOOST_AUTO_TEST_CASE(place_ship)
    {
        auto battlefield_to_test{std::make_unique<std_battlefield>()};

        bool placed_0{battlefield_to_test->place_ship(std::make_shared<std_ship>(1), {{1,1}, {1,1}})};
        BOOST_CHECK(placed_0);

        bool not_placed_0{battlefield_to_test->place_ship(std::make_shared<std_ship>(1), {{1,1}, {1,1}})};
        BOOST_CHECK(!not_placed_0);

        bool placed_1{battlefield_to_test->place_ship(std::make_shared<std_ship>(3), {{2,2}, {2,4}})};
        BOOST_CHECK(placed_1);

        bool not_placed_1{battlefield_to_test->place_ship(std::make_shared<std_ship>(1), {{2,3}, {2,3}})};
        BOOST_CHECK(!not_placed_1);

        bool not_placed_2{battlefield_to_test->place_ship(std::make_shared<std_ship>(5), {{4,2}, {6,3}})};
        BOOST_CHECK(!not_placed_2);
    }

    BOOST_AUTO_TEST_CASE(get_ship)
    {
        auto battlefield_to_test{std::make_unique<std_battlefield>()};

        auto ship_0{std::make_shared<std_ship>(1)};

        bool placed_0{battlefield_to_test->place_ship(ship_0, {{2,2}, {2,2}})};
        BOOST_CHECK(placed_0);
        BOOST_CHECK(ship_0 == battlefield_to_test->get_ship({2,2}));

        auto ship_1{std::make_shared<std_ship>(4)};

        bool placed_1{battlefield_to_test->place_ship(ship_1, {{0,1}, {0,4}})};
        BOOST_CHECK(placed_1);

        BOOST_CHECK(ship_1 == battlefield_to_test->get_ship({0,1}));
        BOOST_CHECK(ship_1 == battlefield_to_test->get_ship({0,2}));
        BOOST_CHECK(ship_1 == battlefield_to_test->get_ship({0,3}));
        BOOST_CHECK(ship_1 == battlefield_to_test->get_ship({0,4}));
    }

    BOOST_AUTO_TEST_CASE(remove_ship_segment)
    {
        auto battlefield_to_test{std::make_unique<std_battlefield>()};

        auto ship_0{std::make_shared<std_ship>(1)};

        bool placed_0{battlefield_to_test->place_ship(ship_0, {{2,2}, {2,2}})};
        BOOST_CHECK(placed_0);

        battlefield_to_test->remove_ship_segment({2,2});

        BOOST_CHECK(!battlefield_to_test->get_ship({2,2}));

        auto ship_1{std::make_shared<std_ship>(4)};

        bool placed_1{battlefield_to_test->place_ship(ship_1, {{1,1}, {1,4}})};
        BOOST_CHECK(!placed_1);

        battlefield_to_test->remove_ship_segment({1,1});
        battlefield_to_test->remove_ship_segment({1,3});
        battlefield_to_test->remove_ship_segment({1,4});

        BOOST_CHECK(!battlefield_to_test->get_ship({1,1}));
        BOOST_CHECK(ship_1 != battlefield_to_test->get_ship({1,2}));
        BOOST_CHECK(!battlefield_to_test->get_ship({1,3}));
        BOOST_CHECK(!battlefield_to_test->get_ship({1,4}));
    }

BOOST_AUTO_TEST_SUITE_END()
