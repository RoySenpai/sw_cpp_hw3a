/*
 *  Software Systems CPP Course Assignment 3
 *  Copyright (C) 2023  Roy Simanovich
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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

    CHECK(a == Fraction(1, 2));
    CHECK(b == Fraction(-1, 2));
    CHECK(c == Fraction(-1, 2));
    CHECK(d == Fraction(1, 2));
    CHECK(e == Fraction(3, 4));
}

TEST_CASE("Test 4: Fraction constructor should reduce the fraction when the numerator is zero")
{
    Fraction a (0, 4); // This is a valid fraction (0/4) = 0
    Fraction b (0, -4); // This is a valid fraction (0/-4) = 0

    CHECK(a == 0);
    CHECK(b == 0);
}

TEST_CASE("Test 5: Arithmetics with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK(a + b == Fraction(5, 6));
    CHECK(a - b == Fraction(1, 6));
    CHECK(a * b == Fraction(1, 6));
    CHECK(a / b == Fraction(3, 2));
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

TEST_CASE("Test 7: Unary operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (-1, 2);
    Fraction c (1, -2);
    Fraction d (-1, -2);

    CHECK(+a == Fraction(1, 2));
    CHECK(-a == Fraction(-1, 2));
    CHECK(+b == Fraction(-1, 2));
    CHECK(-b == Fraction(1, 2));
    CHECK(+c == Fraction(-1, 2));
    CHECK(-c == Fraction(1, 2));
    CHECK(+d == Fraction(1, 2));
    CHECK(-d == Fraction(-1, 2));
}

TEST_CASE("Test 8: Compound assignment operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    a += b;
    CHECK(a == Fraction(5, 6));

    a -= b;
    CHECK(a == Fraction(1, 2));

    a *= b;
    CHECK(a == Fraction(1, 6));

    a /= b;
    CHECK(a == Fraction(1, 2));
}

TEST_CASE("Test 9: Increment and decrement operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK(++a == Fraction(3, 2));
    CHECK(a++ == Fraction(3, 2));
    CHECK(a == Fraction(5, 2));

    CHECK(--b == Fraction(-2, 3));
    CHECK(b-- == Fraction(-2, 3));
    CHECK(b == Fraction(-5, 3));
}

TEST_CASE("Test 10: I/O operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK_NOTHROW(cout << a << endl);
    CHECK_NOTHROW(cout << b << endl);
}

TEST_CASE("Test 11: Type conversion operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK(a == 0);
    CHECK(b == 0);
    CHECK(a == 0.5);
    CHECK(b == 0.333333333333333);
}

TEST_CASE("Test 12: Mixed type operators with fractions")
{
    Fraction a (1, 2);

    CHECK((a + 1) == Fraction(3, 2));
    CHECK((1 + a) == Fraction(3, 2));
    CHECK((a - 1) == Fraction(-1, 2));
    CHECK((1 - a) == Fraction(1, 2));
    CHECK((a * 2) == Fraction(1, 1));
    CHECK((2 * a) == Fraction(1, 1));
    CHECK((a / 2) == Fraction(1, 4));
    CHECK((2 / a) == Fraction(4, 1));

    CHECK((a > 1) == false);
    CHECK((1 > a) == true);
    CHECK((a < 1) == true);
    CHECK((1 < a) == false);
    CHECK((a >= 1) == false);
    CHECK((1 >= a) == true);
    CHECK((a <= 1) == true);
    CHECK((1 <= a) == false);
    CHECK((a == 1) == false);
    CHECK((1 == a) == false);
    CHECK((a != 1) == true);
    CHECK((1 != a) == true);
}

TEST_CASE("Test 13: Mixed type compound assignment operators with fractions")
{
    Fraction a (1, 2);

    a += 1;
    CHECK(a == Fraction(3, 2));

    a -= 1;
    CHECK(a == Fraction(1, 2));

    a *= 2;
    CHECK(a == Fraction(1, 1));

    a /= 2;
    CHECK(a == Fraction(1, 2));
}

