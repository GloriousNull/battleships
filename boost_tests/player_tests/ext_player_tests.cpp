//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/players/std_player.h"
#include "../../src/players/ext_player.h"

#include "../../src/ships/std_ship.h"
#include "../../src/ships/ext_ship_mine.h"

BOOST_AUTO_TEST_SUITE(ext_player_test)

    BOOST_AUTO_TEST_CASE(place_ship)
    {
        std::unique_ptr<ext_player_base> player_to_test{std::make_unique<ext_player>()};

        bool is_placed_0{player_to_test->place_ship(std_ship{3}, {{1, 1},{1, 3}})};
        BOOST_CHECK(is_placed_0);

        bool is_placed_1{player_to_test->place_ship(std_ship{3}, {{1, 1},{1, 3}})};
        BOOST_CHECK(!is_placed_1);

        bool is_placed_2{player_to_test->place_ship(ext_ship_mine{3}, {{2, 1},{2, 3}})};
        BOOST_CHECK(is_placed_2);

        bool is_placed_3{player_to_test->place_ship(ext_ship_mine{3}, {{2, 0},{2, 2}})};
        BOOST_CHECK(!is_placed_3);
    }

    BOOST_AUTO_TEST_CASE(attack)
    {
        std::shared_ptr<ext_player_base> player_to_test_0{std::make_shared<ext_player>()};
        std::shared_ptr<ext_player_base> player_to_test_1{std::make_shared<ext_player>()};

        bool is_placed_0{player_to_test_0->place_ship(std_ship{3}, {{1, 1},{1, 3}})};
        BOOST_CHECK(is_placed_0);

        bool is_placed_1{player_to_test_0->place_ship(ext_ship_mine{3}, {{2, 1},{2, 3}})};
        BOOST_CHECK(is_placed_1);

        auto[revealed_0, hit_0]{player_to_test_1->attack(player_to_test_0, {1, 1})};
        BOOST_CHECK(!player_to_test_1->has_duty());
        BOOST_CHECK(revealed_0 && hit_0);

        auto[revealed_1, hit_1]{player_to_test_1->attack(player_to_test_0, {2, 1})};
        BOOST_CHECK(!player_to_test_1->has_duty());
        BOOST_CHECK(revealed_1 && hit_1);

        auto[revealed_2, hit_2]{player_to_test_1->attack(player_to_test_0, {2, 2})};
        BOOST_CHECK(!player_to_test_1->has_duty());
        BOOST_CHECK(revealed_2 && hit_2);

        auto[revealed_3, hit_3]{player_to_test_1->attack(player_to_test_0, {2, 3})};
        BOOST_CHECK(player_to_test_1->has_duty());
        BOOST_CHECK(revealed_3 && hit_3);

        auto[revealed_4, hit_4]{player_to_test_1->attack(player_to_test_0, {0, 0})};
        BOOST_CHECK(revealed_4 && !hit_4);

        auto[revealed_5, hit_5]{player_to_test_1->attack(player_to_test_0, {0, 0})};
        BOOST_CHECK(!revealed_5 && !hit_5);

        auto[revealed_42, hit_42]{player_to_test_1->attack(player_to_test_0, {1, 1})};
        BOOST_CHECK(!revealed_42 && !hit_42);
    }

    BOOST_AUTO_TEST_CASE(kill_self_ship)
    {
        std::unique_ptr<ext_player_base> player_to_test{std::make_unique<ext_player>()};

        bool is_placed_0{player_to_test->place_ship(std_ship{3}, {{1, 1},{1, 3}})};
        BOOST_CHECK(is_placed_0 && player_to_test->kill_self({1,1}));
        BOOST_CHECK(!player_to_test->kill_self({1,1}));
    }

    BOOST_AUTO_TEST_CASE(reveal_self_ship)
    {
        std::unique_ptr<ext_player_base> player_to_test{std::make_unique<ext_player>()};

        bool is_placed_0{player_to_test->place_ship(std_ship{3}, {{1, 1},{1, 3}})};
        BOOST_CHECK(is_placed_0 && player_to_test->reveal_self_ship({1,1}));
        BOOST_CHECK(!player_to_test->reveal_self_ship({1,1}));
    }

BOOST_AUTO_TEST_SUITE_END()
