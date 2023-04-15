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