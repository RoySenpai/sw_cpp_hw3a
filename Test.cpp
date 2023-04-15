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

    CHECK((float)a == 0.5);
    CHECK((float)b == -0.5);
    CHECK((float)c == -0.5);
    CHECK((float)d == 0.5);
    CHECK((float)e == 0.75);
}

TEST_CASE("Test 4: Fraction constructor should reduce the fraction when the numerator is zero")
{
    Fraction a (0, 4); // This is a valid fraction (0/4) = 0
    Fraction b (0, -4); // This is a valid fraction (0/-4) = 0

    CHECK((float)a == 0);
    CHECK((float)b == 0);
}

TEST_CASE("Test 5: Arithmetics with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((float)(a + b) == 0.833333333333333);
    CHECK((float)(a - b) == 0.166666666666667);
    CHECK((float)(a * b) == 0.166666666666667);
    CHECK((float)(a / b) == 1.5);
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

    CHECK((float)(+a) == 0.5);
    CHECK((float)(-a) == -0.5);
    CHECK((float)(+b) == -0.5);
    CHECK((float)(-b) == 0.5);
    CHECK((float)(+c) == -0.5);
    CHECK((float)(-c) == 0.5);
    CHECK((float)(+d) == 0.5);
    CHECK((float)(-d) == -0.5);
}

TEST_CASE("Test 8: Compound assignment operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    a += b;
    CHECK((float)a == 0.833333333333333);

    a -= b;
    CHECK((float)a == 0.5);

    a *= b;
    CHECK((float)a == 0.166666666666667);

    a /= b;
    CHECK((float)a == 0.5);
}

TEST_CASE("Test 9: Increment and decrement operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((float)(++a) == 0.75);
    CHECK((float)(a++) == 0.75);
    CHECK((float)a == 1.25);

    CHECK((float)(--b) == 0.333333333333333);
    CHECK((float)(b--) == 0.333333333333333);
    CHECK((float)b == -0.666666666666667);
}

TEST_CASE("Test 10: I/O operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    cout << a << endl;
    cout << b << endl;
}

TEST_CASE("Test 11: Type conversion operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((int)a == 0);
    CHECK((int)b == 0);
    CHECK((float)a == 0.5);
    CHECK((float)b == 0.333333333333333);
}

TEST_CASE("Test 12: Mixed type operators with fractions")
{
    Fraction a (1, 2);
    Fraction b (1, 3);

    CHECK((float)(a + 1) == 1.5);
    CHECK((float)(1 + a) == 1.5);
    CHECK((float)(a - 1) == -0.5);
    CHECK((float)(1 - a) == 0.5);
    CHECK((float)(a * 2) == 1);
    CHECK((float)(2 * a) == 1);
    CHECK((float)(a / 2) == 0.25);
    CHECK((float)(2 / a) == 4);

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
    Fraction b (1, 3);

    a += 1;
    CHECK((float)a == 1.5);

    a -= 1;
    CHECK((float)a == 0.5);

    a *= 2;
    CHECK((float)a == 1);

    a /= 2;
    CHECK((float)a == 0.5);
}