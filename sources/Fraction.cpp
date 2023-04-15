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

#include "Fraction.hpp"

namespace ariel
{
    Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {
        if (denominator == 0)
            throw std::invalid_argument("Denominator can't be zero");

        if (denominator < 0)
        {
            this->numerator *= -1;
            this->denominator *= -1;
        }

        __reduce();
    }

    Fraction::Fraction(double number) {
        int power = 1;
        while (number != (int)number && power < 1000)
        {
            number *= 10;
            power *= 10;
        }

        this->numerator = number;
        this->denominator = power;

        __reduce();
    }

    void Fraction::__reduce() {
        int gcd = __gcd(this->numerator, this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
    }
}