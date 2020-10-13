//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/ships/ext_ship_minesweeper.h"

#include "../../src/players/std_player.h"
#include "../../src/players/ext_player.h"

BOOST_AUTO_TEST_SUITE(ext_ship_minesweeper_test)

    BOOST_AUTO_TEST_CASE(on_destroy)
    {
        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<ext_ship_minesweeper>(0);

        std::shared_ptr<std_player_base> player_42 = std::make_shared<std_player>();
        bool placed_0 = player_42->place_ship(ext_ship_minesweeper(1), {{1,1},{1,1}});

        std::shared_ptr<std_player_base> player_451 = std::make_shared<ext_player>();
        bool placed_1 = player_451->place_ship(ext_ship_minesweeper(1), {{1,1},{1,1}});

        auto checked_ship = dynamic_cast<ext_ship_base*>(ship_to_test.get());
        auto duty = checked_ship->on_destroy();

        BOOST_CHECK(placed_0 && placed_1);

        duty.try_to_fulfill(player_42, {1,1});

        BOOST_CHECK(duty.is_fulfilled() == false);

        duty.try_to_fulfill(player_451, {1,1});

        BOOST_CHECK(duty.is_fulfilled() == true);
    }

    BOOST_AUTO_TEST_CASE(destroyed)
    {
        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<ext_ship_minesweeper>(0);

        BOOST_CHECK(ship_to_test->is_destroyed() == true);
    }

    BOOST_AUTO_TEST_CASE(not_destroyed)
    {
        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<ext_ship_minesweeper>(1);

        BOOST_CHECK(ship_to_test->is_destroyed() == false);
    }

    BOOST_AUTO_TEST_CASE(size)
    {
        constexpr std::size_t size{5};

        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<ext_ship_minesweeper>(size);

        BOOST_CHECK(ship_to_test->size() == size);
    }

    BOOST_AUTO_TEST_CASE(damage_taken)
    {
        constexpr std::size_t size{1};

        std::shared_ptr<std_ship_base> ship_to_test = std::make_shared<ext_ship_minesweeper>(size);
        ship_to_test->apply_damage();

        BOOST_CHECK(ship_to_test->size() == size - 1);
    }

BOOST_AUTO_TEST_SUITE_END()
