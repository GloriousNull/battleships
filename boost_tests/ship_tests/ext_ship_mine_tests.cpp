//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/ships/ext_ship/ext_ship_mine.h"

#include "../../src/players/std_player/std_player.h"
#include "../../src/players/ext_player/ext_player.h"

BOOST_AUTO_TEST_SUITE(ext_ship_mine_test)

    BOOST_AUTO_TEST_CASE(on_destroy)
    {
        std::unique_ptr<ship_base> ship_to_test{std::make_unique<ext_ship_mine>(0)};

        std::shared_ptr<ext_player_base> player_451{std::make_shared<ext_player>()};
        bool placed_1 = player_451->place_ship(std::make_shared<ext_ship_mine>(1), {{1,1},{1,1}});
        BOOST_CHECK(placed_1);

        auto checked_ship{dynamic_cast<ext_ship_base*>(ship_to_test.get())};
        BOOST_CHECK(checked_ship);
        auto duty = checked_ship->on_destroy();


        duty.try_to_fulfill(*player_451, {1,1});
        BOOST_CHECK(duty.is_fulfilled());
    }

    BOOST_AUTO_TEST_CASE(destroyed)
    {
        std::unique_ptr<ship_base> ship_to_test = std::make_unique<ext_ship_mine>(0);

        BOOST_CHECK(ship_to_test->is_destroyed());
    }

    BOOST_AUTO_TEST_CASE(not_destroyed)
    {
        std::unique_ptr<ship_base> ship_to_test = std::make_unique<ext_ship_mine>(1);

        BOOST_CHECK(!ship_to_test->is_destroyed());
    }

    BOOST_AUTO_TEST_CASE(size)
    {
        constexpr std::size_t size{5};

        std::unique_ptr<ship_base> ship_to_test = std::make_unique<ext_ship_mine>(size);

        BOOST_CHECK(ship_to_test->size() == size);
    }

    BOOST_AUTO_TEST_CASE(damage_taken)
    {
        constexpr std::size_t size{1};

        std::unique_ptr<ship_base> ship_to_test = std::make_unique<ext_ship_mine>(size);
        ship_to_test->apply_damage();

        BOOST_CHECK(ship_to_test->durability() == size - 1 && ship_to_test->size() == size);
    }

BOOST_AUTO_TEST_SUITE_END()
