//
// Created by GloriousSir on 10/13/2020.
//

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "../../src/utils/duty.h"

BOOST_AUTO_TEST_SUITE(duty_test)

    BOOST_AUTO_TEST_CASE(fullfield)
    {
        duty<> duty_to_test{+[](){return true;}};

        duty_to_test.try_to_fulfill();

        BOOST_CHECK(duty_to_test.is_fulfilled() == true);
    }

    BOOST_AUTO_TEST_CASE(not_fullfield)
    {
        duty<> duty_to_test{+[](){return false;}};

        duty_to_test.try_to_fulfill();

        BOOST_CHECK(duty_to_test.is_fulfilled() == false);
    }

    BOOST_AUTO_TEST_CASE(setter)
    {
        duty<const std::size_t &> duty_to_test;

        duty_to_test.set_work(+[](const std::size_t & number){ return number > 2;});

        BOOST_CHECK(duty_to_test.is_fulfilled() == false);

        duty_to_test.try_to_fulfill(3);

        BOOST_CHECK(duty_to_test.is_fulfilled() == true);
    }

BOOST_AUTO_TEST_SUITE_END()
