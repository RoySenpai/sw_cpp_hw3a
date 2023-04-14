#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1: Fraction constructor throws exception when denominator is zero")
{
    // The following line should throw an exception of type "invalid_argument"
    CHECK_THROWS(Fraction(1, 0));

    // This is a valid fraction (1/-1) = -1
    CHECK_NOTHROW(Fraction(1, -1));

    // The following line should throw an exception of type "invalid_argument"
    CHECK_THROWS(Fraction(-1, 0));

    // This is a valid fraction (-1/-1) = 1
    CHECK_NOTHROW(Fraction(-1, -1));
}