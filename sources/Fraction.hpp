#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>

namespace ariel
{
    class Fraction
    {
        private:
            /*
             * @brief The numerator of the fraction.
             * @note The numerator is the top number of the fraction.
            */
            int numerator;
            
            /*
             * @brief The denominator of the fraction.
             * @note The denominator is the bottom number of the fraction.
             * @note The denominator can't be 0.
            */
            int denominator;

            /*
             * @brief Reduces the fraction to its simplest form.
             * @note This function is private because it is only used internally.
            */
            void reduce();

            /*
             * @brief Calculates the greatest common divisor of two numbers.
             * @param a The first number.
             * @param b The second number.
             * @return int The greatest common divisor of the two numbers.
             * @note This function is used to reduce the fraction to its simplest form.
             * @note This function is private because it is only used internally.
             * @note This function is static because it is only used internally and doesn't require an instance of the class.
            */
            static int __gcd(int a, int b) {
                return (b == 0) ? a:__gcd(b, a % b);
            }

        public:
            /*********************/
            /* Constructors zone */
            /*********************/

            /*
             * @brief Default constructor of the Fraction class.
             * @note The default fraction is 0/1 (zero).
            */
            Fraction(): numerator(0), denominator(1) {};

            /*
             * @brief Construct a new Fraction object
             * @param numerator The numerator of the fraction.
             * @param denominator The denominator of the fraction.
             * @throw invalid_argument if the denominator is 0.
             * @note The fraction will be reduced to its simplest form.
            */
            Fraction(int numerator, int denominator);

            /*
             * @brief Copy constructor of the Fraction class.
             * @param other The fraction to copy.
            */
            Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {};

            /*
             * @brief Move constructor of the Fraction class.
             * @param other The fraction to move.
             * @note This constructor is used to move the fraction to another fraction.
            */
            Fraction(Fraction&& other): numerator(other.numerator), denominator(other.denominator) {};

            /*
             * @brief A destructor of the Fraction class.
             * @note This destructor is default because it doesn't do anything.
            */
            ~Fraction() = default;

            /***************************/
            /* Operators overload zone */
            /***************************/

            /*
             * @brief Assigns a fraction to another fraction.
             * @param other The fraction to assign.
             * @return Fraction& The assigned fraction.
            */
            Fraction& operator=(const Fraction& other);

            /*
             * @brief Assigns a fraction to another fraction.
             * @param other The fraction to assign.
             * @return Fraction& The assigned fraction.
             * @note This function is used to move the fraction to another fraction.
            */
            Fraction& operator=(Fraction&& other);

            /*
             * @brief Prints the fraction to the output stream.
             * @param os The output stream.
             * @return std::ostream& The output stream.
             * @note This function is used to print the fraction to the output stream.
            */
            std::ostream& operator<<(std::ostream& os) {
                os << numerator << "/" << denominator;
                return os;
            }

            /*
             * @brief Reads the fraction from the input stream.
             * @param is The input stream.
             * @return std::istream& The input stream.
             * @note This function is used to read the fraction from the input stream.
            */
            std::istream& operator>>(std::istream& is);

            /*
             * @brief Adds two fractions.
             * @param other The fraction to add.
             * @return Fraction The result of the addition.
            */
            Fraction operator+(const Fraction& other) const {
                return Fraction((numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator);
            }

            /*
             * @brief Subtracts two fractions.
             * @param other The fraction to subtract.
             * @return Fraction The result of the subtraction.
            */
            Fraction operator-(const Fraction& other) const {
                return Fraction((numerator * other.denominator) - (other.numerator * denominator), denominator * other.denominator);
            }

            /*
             * @brief Multiplies two fractions.
             * @param other The fraction to multiply.
             * @return Fraction The result of the multiplication.
            */
            Fraction operator*(const Fraction& other) const {
                return Fraction(numerator * other.numerator, denominator * other.denominator);
            }

            /*
             * @brief Divides two fractions.
             * @param other The fraction to divide.
             * @return Fraction The result of the division.
            */
            Fraction operator/(const Fraction& other) const {
                return Fraction(numerator * other.denominator, denominator * other.numerator);
            }

            /*
             * @brief Returns the fraction.
             * @return Fraction The fraction.
            */
            Fraction operator+() const {
                return Fraction(numerator, denominator);
            }

            /*
             * @brief Negates the fraction.
             * @return Fraction The negated fraction.
            */
            Fraction operator-() const {
                return Fraction(-numerator, denominator);
            }

            /*
             * @brief Adds a fraction to the current fraction.
             * @param other The fraction to add.
             * @return Fraction& The current fraction.
            */
            Fraction& operator+=(const Fraction& other);

            /*
             * @brief Subtracts a fraction from the current fraction.
             * @param other The fraction to subtract.
             * @return Fraction& The current fraction.
            */
            Fraction& operator-=(const Fraction& other);

            /*
             * @brief Multiplies the current fraction by a fraction.
             * @param other The fraction to multiply.
             * @return Fraction& The current fraction.
            */
            Fraction& operator*=(const Fraction& other);

            /*
             * @brief Divides the current fraction by a fraction.
             * @param other The fraction to divide.
             * @return Fraction& The current fraction.
            */
            Fraction& operator/=(const Fraction& other);

            /*
             * @brief Increments the current fraction by 1 (pre-increment).
             * @return Fraction& The current fraction.
            */
            Fraction& operator++();

            /*
             * @brief Decrements the current fraction by 1 (pre-decrement).
             * @return Fraction& The current fraction.
            */
            Fraction& operator--();

            /*
             * @brief Increments the current fraction by 1 (post-increment).
             * @return Fraction The current fraction.
            */
            Fraction operator++(int);

            /*
             * @brief Decrements the current fraction by 1 (post-decrement).
             * @return Fraction The current fraction.
            */
            Fraction operator--(int);


            /*********************************/
            /* Comparison operators overload */
            /*********************************/

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            bool operator==(const Fraction& other) const {
                return (numerator == other.numerator && denominator == other.denominator);
            }

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the fractions are not equal, false otherwise.
            */
            bool operator!=(const Fraction& other) const {
                return (numerator != other.numerator || denominator != other.denominator);
            }

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the current fraction is greater than the other fraction, false otherwise.
            */
            bool operator>(const Fraction& other) const {
                return (double)*this > (double)other;
            }

            /* 
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the current fraction is less than the other fraction, false otherwise.
            */
            bool operator<(const Fraction& other) const {
                return (double)*this < (double)other;
            }

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the current fraction is greater than or equal to the other fraction, false otherwise.
            */
            bool operator>=(const Fraction& other) const {
                return (double)*this >= (double)other;
            }

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the current fraction is less than or equal to the other fraction, false otherwise.
            */
            bool operator<=(const Fraction& other) const {
                return (double)*this <= (double)other;
            }


            /*******************************************/
            /* Conversion (casting) operators overload */
            /*******************************************/

            /*
             * @brief Converts the fraction to an integer.
             * @return The integer value of the fraction (rounded down).
            */
            operator int () const {
                return (int)((double)numerator / denominator);
            }

            /*
             * @brief Converts the fraction to a double.
             * @return The double value of the fraction.
            */
            operator double() const {
                return (double)numerator / denominator;
            }

            /*
             * @brief Converts the fraction to a string.
             * @return The string value of the fraction.
            */
            operator std::string() const {
                return std::to_string(numerator) + "/" + std::to_string(denominator);
            }
    };
}