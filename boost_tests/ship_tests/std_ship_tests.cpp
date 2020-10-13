//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

#include "../../src/ships/std_ship.h"

BOOST_AUTO_TEST_SUITE(std_ship_test)

    BOOST_AUTO_TEST_CASE(destroyed)
    {
        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<std_ship>(0);

        BOOST_CHECK(ship_to_test->is_destroyed() == true);
    }

    BOOST_AUTO_TEST_CASE(not_destroyed)
    {
        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<std_ship>(4);

        BOOST_CHECK(ship_to_test->is_destroyed() == false);
    }

    BOOST_AUTO_TEST_CASE(size)
    {
        constexpr std::size_t size{5};

        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<std_ship>(size);

        BOOST_CHECK(ship_to_test->size() == size);
    }

    BOOST_AUTO_TEST_CASE(damage_taken)
    {
        constexpr std::size_t size{1};

        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<std_ship>(size);
        ship_to_test->apply_damage();

        BOOST_CHECK(ship_to_test->size() == size - 1);
    }

BOOST_AUTO_TEST_SUITE_END()
