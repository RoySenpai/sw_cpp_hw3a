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

TEST_CASE("Test 2: Fraction constructor shouldn't throw exception when only the numerator is zero")
{
    // This is a valid fraction (0/1) = 0
    CHECK_NOTHROW(Fraction(0, 1));

    // This is a valid fraction (0/-1) = 0
    CHECK_NOTHROW(Fraction(0, -1));
}

TEST_CASE("Test 3: Fraction constructor should reduce the fraction")
{
    Fraction a (2, 4); // This is a valid fraction (2/4) = 1/2
    Fraction b (-2, 4); // This is a valid fraction (-2/4) = -1/2
    Fraction c (2, -4); // This is a valid fraction (2/-4) = -1/2
    Fraction d (-2, -4); // This is a valid fraction (-2/-4) = 1/2
    Fraction e (3, 4); // This is a valid fraction (3/4) = 0.75 (Note: 3/4 can't be reduced)

    CHECK((double)a == 0.5);
    CHECK((double)b == -0.5);
    CHECK((double)c == -0.5);
    CHECK((double)d == 0.5);
    CHECK((double)e == 0.75);
}

TEST_CASE("Test 4: Fraction constructor should reduce the fraction when the numerator is zero")
{
    Fraction a (0, 4); // This is a valid fraction (0/4) = 0
    Fraction b (0, -4); // This is a valid fraction (0/-4) = 0

    CHECK((double)a == 0);
    CHECK((double)b == 0);
}

TEST_CASE("Test 5: Arithmetics with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((double)(a + b) == 0.833333333333333);
    CHECK((double)(a - b) == 0.166666666666667);
    CHECK((double)(a * b) == 0.166666666666667);
    CHECK((double)(a / b) == 1.5);
}

TEST_CASE("Test 6: Comparison operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((a > b) == true);
    CHECK((a < b) == false);
    CHECK((a >= b) == true);
    CHECK((a <= b) == false);
    CHECK((a == b) == false);
    CHECK((a != b) == true);
}
