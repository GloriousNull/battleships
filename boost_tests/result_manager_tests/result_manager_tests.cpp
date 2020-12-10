//
// Created by GloriousSir on 11/15/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/game/result_manager/result_manager.h"

BOOST_AUTO_TEST_SUITE(result_manager_test)

    BOOST_AUTO_TEST_CASE(sending_and_receiving)
    {
        result_manager rm;

        game_result gr_1984{"John Doe", 1985};
        rm.send(gr_1984);
        auto results = rm.receive();

        BOOST_CHECK(results[1].winner_name == gr_1984.winner_name
                    && results[1].amount_of_turns != gr_1984.amount_of_turns);

        game_result gr_42{"GloriousSir", 42};
        rm.send(gr_42);

        results = rm.receive();
        BOOST_CHECK(results[2].winner_name == gr_42.winner_name
                    && results[2].amount_of_turns == gr_42.amount_of_turns);
    }

    BOOST_AUTO_TEST_CASE(receiving_by_name)
    {
        result_manager rm;

        const char * name = "Warren";

        auto results = rm.receive(name);

        BOOST_CHECK(!results.empty());
        for (const auto & el : results)
            BOOST_CHECK(el.winner_name == name);

        results = rm.receive("what was that?");

        BOOST_CHECK(results.empty());
    }

BOOST_AUTO_TEST_SUITE_END()