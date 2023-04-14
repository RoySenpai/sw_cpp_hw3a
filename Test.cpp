#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Fraction constructor throws exception when denominator is zero")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_NOTHROW(Fraction(1, -1));
    CHECK_THROWS(Fraction(-1, 0));
    CHECK_NOTHROW(Fraction(-1, -1));
}