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
            void __reduce();

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
             * @brief Convert constructor from int to Fraction.
             * @param numerator The numerator of the fraction.
             * @note The denominator of the fraction is 1.
             * @note This constructor is used to convert an integer to a fraction.
            */
            Fraction(int numerator): numerator(numerator), denominator(1) {};

            /*
             * @brief Convert constructor from double to Fraction.
             * @param number The number to convert to a fraction.
             * @note This constructor is used to convert a double to a fraction.
            */
            Fraction(double number);

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
            Fraction(Fraction&& other) noexcept: numerator(other.numerator), denominator(other.denominator) {};

            /*
             * @brief A destructor of the Fraction class.
             * @note This destructor is default because it doesn't do anything.
            */
            ~Fraction() = default;


            /**************************************************/
            /* Operators overload zone - Assignment operators */
            /**************************************************/

            /*
             * @brief Assigns a fraction to another fraction.
             * @param other The fraction to assign.
             * @return Fraction& The assigned fraction.
             * @TODO Implement this function.
            */
            Fraction& operator=(const Fraction& other) {
                return *this;
            }

            /*
             * @brief Assigns a fraction to another fraction.
             * @param other The fraction to assign.
             * @return Fraction& The assigned fraction.
             * @note This function is used to move the fraction to another fraction.
             * @TODO Implement this function.
            */
            Fraction& operator=(Fraction&& other) noexcept {
                return *this;
            }


            /**********************************************/
            /* Operators overload zone - Stream operators */
            /**********************************************/

            /*
             * @brief Prints the fraction to the output stream.
             * @param os The output stream.
             * @return std::ostream& The output stream.
             * @note This function is used to print the fraction to the output stream.
            */
            std::ostream& operator<<(std::ostream& os) const {
                return os << numerator << "/" << denominator;
            }

            /*
             * @brief Reads the fraction from the input stream.
             * @param is The input stream.
             * @return std::istream& The input stream.
             * @note This function is used to read the fraction from the input stream.
             * @TODO Implement this function.
            */
            std::istream& operator>>(std::istream& is) const {
                return is;
            }


            /**************************************************/
            /* Operators overload zone - Arithmetic operators */
            /**************************************************/

            /*
             * @brief Adds two fractions.
             * @param other The fraction to add.
             * @return Fraction The result of the addition.
            */
            Fraction operator+(const Fraction& other) const {
                return Fraction(((numerator * other.denominator) + (other.numerator * denominator)), (denominator * other.denominator));
            }

            /*
             * @brief Adds a fraction to a double.
             * @param num The double to add.
             * @return Fraction The result of the addition.
            */
            Fraction operator+(const double num) const {
                return *this + Fraction(num);
            }

            /*
             * @brief Adds a fraction to a double.
             * @param num The double to add.
             * @param other The fraction to add.
             * @return Fraction The result of the addition.
            */
            friend Fraction operator+(const double num, const Fraction& other) {
                return Fraction(num) + other;
            }

            /*
             * @brief Adds a fraction to an integer.
             * @param num The integer to add.
             * @return Fraction The result of the addition.
            */
            Fraction operator+(const int num) const {
                return *this + Fraction(num);
            }

            /*
             * @brief Adds a fraction to an integer.
             * @param num The integer to add.
             * @param other The fraction to add.
             * @return Fraction The result of the addition.
            */
            friend Fraction operator+(const int num, const Fraction& other) {
                return Fraction(num) + other;
            }

            /*
             * @brief Subtracts two fractions.
             * @param other The fraction to subtract.
             * @return Fraction The result of the subtraction.
            */
            Fraction operator-(const Fraction& other) const {
                return Fraction(((numerator * other.denominator) - (other.numerator * denominator)), (denominator * other.denominator));
            }

            /*
             * @brief Subtracts a fraction from a double.
             * @param num The double to subtract.
             * @return Fraction The result of the subtraction.
            */
            Fraction operator-(const double num) const {
                return *this - Fraction(num);
            }

            /*
             * @brief Subtracts a fraction from a double.
             * @param num The double to subtract.
             * @param other The fraction to subtract.
            */
            friend Fraction operator-(const double num, const Fraction& other) {
                return Fraction(num) - other;
            }

            /*
             * @brief Subtracts a fraction from an integer.
             * @param num The integer to subtract.
             * @return Fraction The result of the subtraction.
            */
            Fraction operator-(int num) const {
                return Fraction(num * denominator - numerator, denominator);
            }

            /*
             * @brief Subtracts a fraction from an integer.
             * @param num The integer to subtract.
             * @param other The fraction to subtract.
            */
            friend Fraction operator-(int num, const Fraction& other) {
                return Fraction(num * other.denominator - other.numerator, other.denominator);
            }

            /*
             * @brief Multiplies two fractions.
             * @param other The fraction to multiply.
             * @return Fraction The result of the multiplication.
            */
            Fraction operator*(const Fraction& other) const {
                return Fraction((numerator * other.numerator), (denominator * other.denominator));
            }

            /*
             * @brief Multiplies a fraction by a double.
             * @param num The double to multiply.
             * @return Fraction The result of the multiplication.
            */
            Fraction operator*(const double num) const {
                return *this * Fraction(num);
            }

            /*
             * @brief Multiplies a fraction by a double.
             * @param num The double to multiply.
             * @param other The fraction to multiply.
             * @return Fraction The result of the multiplication.
            */
            friend Fraction operator*(const double num, const Fraction& other) {
                return Fraction(num) * other;
            }

            /*
             * @brief Multiplies a fraction by an integer.
             * @param num The integer to multiply.
             * @return Fraction The result of the multiplication.
            */
            Fraction operator*(const int num) const {
                return *this * Fraction(num);
            }

            /*
             * @brief Multiplies a fraction by an integer.
             * @param num The integer to multiply.
             * @param other The fraction to multiply.
             * @return Fraction The result of the multiplication.
            */
            friend Fraction operator*(const int num, const Fraction& other) {
                return Fraction(num) * other;
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
             * @brief Divides a fraction by a double.
             * @param num The double to divide.
             * @return Fraction The result of the division.
            */
            Fraction operator/(const double num) const {
                return *this / Fraction(num);
            }

            /*
             * @brief Divides a fraction by a double.
             * @param num The double to divide.
             * @param other The fraction to divide.
             * @return Fraction The result of the division.
            */
            friend Fraction operator/(const double num, const Fraction& other) {
                return Fraction(num) / other;
            }

            /*
             * @brief Divides a fraction by an integer.
             * @param num The integer to divide.
             * @return Fraction The result of the division.
            */
            Fraction operator/(const int num) const {
                return *this / Fraction(num);
            }

            /*
             * @brief Divides a fraction by an integer.
             * @param num The integer to divide.
             * @param other The fraction to divide.
             * @return Fraction The result of the division.
            */
            friend Fraction operator/(const int num, const Fraction& other) {
                return Fraction(num) / other;
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

            
            /**************************************************/
            /* Operators overload zone - Assignment operators */
            /**************************************************/

            /*
             * @brief Adds a fraction to the current fraction.
             * @param other The fraction to add.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator+=(const Fraction& other) {
                return *this;
            }

            /*
             * @brief Adds a double to the current fraction.
             * @param num The double to add.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator+=(const double num) {
                return *this;
            }

            /* 
             * @brief Adds an integer to the current fraction.
             * @param num The integer to add.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator+=(const int num) {
                return *this;
            }

            /*
             * @brief Subtracts a fraction from the current fraction.
             * @param other The fraction to subtract.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator-=(const Fraction& other) {
                return *this;
            }

            /* 
             * @brief Adds a double to the current fraction.
             * @param num The double to add.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator-=(const double num) {
                return *this;
            }

            /* 
             * @brief Adds an integer to the current fraction.
             * @param num The integer to add.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator-=(const int num) {
                return *this;
            }

            /*
             * @brief Multiplies the current fraction by a fraction.
             * @param other The fraction to multiply.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator*=(const Fraction& other) {
                return *this;
            }

            /*
             * @brief Multiplies the current fraction by a double.
             * @param num The double to multiply.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator*=(const double num) {
                return *this;
            }

            /*
             * @brief Multiplies the current fraction by an integer.
             * @param num The integer to multiply.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator*=(const int num) {
                return *this;
            }

            /*
             * @brief Divides the current fraction by a fraction.
             * @param other The fraction to divide.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator/=(const Fraction& other) {
                return *this;
            }

            /*
             * @brief Divides the current fraction by a double.
             * @param num The double to divide.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator/=(const double num) {
                return *this;
            }

            /*
             * @brief Divides the current fraction by an integer.
             * @param num The integer to divide.
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator/=(const int num) {
                return *this;
            }

            /*
             * @brief Increments the current fraction by 1 (pre-increment).
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator++() {
                return *this;
            }

            /*
             * @brief Decrements the current fraction by 1 (pre-decrement).
             * @return Fraction& The current fraction.
             * @TODO Implement this function.
            */
            Fraction& operator--() {
                return *this;
            }

            /*
             * @brief Increments the current fraction by 1 (post-increment).
             * @return Fraction The current fraction.
             * @TODO Implement this function.
            */
            Fraction operator++(int) {
                return *this;
            }

            /*
             * @brief Decrements the current fraction by 1 (post-decrement).
             * @return Fraction The current fraction.
             * @TODO Implement this function.
            */
            Fraction operator--(int) {
                return *this;
            }


            /**************************************************/
            /* Operators overload zone - Compersion operators */
            /**************************************************/

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            bool operator==(const Fraction& other) const {
                return (numerator == other.numerator && denominator == other.denominator);
            }

            /*
             * @brief Compares a fraction and an double.
             * @param other The double to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            bool operator==(const double& other) const {
                return (double)*this == other;
            }

            /*
             * @brief Compares a fraction and an double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            friend bool operator==(const double& num, const Fraction& other) {
                return (double)other == num;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            bool operator==(const int& other) const {
                return (double)*this == other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the fractions are equal, false otherwise.
            */
            friend bool operator==(const int& num, const Fraction& other) {
                return (double)other == (double)num;
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
             * @brief Compares a fraction and an double.
             * @param other The double to compare.
             * @return True if the fractions are not equal, false otherwise.
            */
            bool operator!=(const double& other) const {
                return (double)*this != other;
            }

            /*
             * @brief Compares a fraction and an double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the fractions are not equal, false otherwise.
            */
            friend bool operator!=(const double& num, const Fraction& other) {
                return (double)other != num;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the fractions are not equal, false otherwise.
            */
            bool operator!=(const int& other) const {
                return (double)*this != (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the fractions are not equal, false otherwise.
            */
            friend bool operator!=(const int& num, const Fraction& other) {
                return (double)other != (double)num;
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
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @return True if the current fraction is greater than the double, false otherwise.
            */
            bool operator>(const double& other) const {
                return (double)*this > other;
            }

            /*
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is greater than the double, false otherwise.
            */
            friend bool operator>(const double& num, const Fraction& other) {
                return num > (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the current fraction is greater than the integer, false otherwise.
            */
            bool operator>(const int& other) const {
                return (double)*this > (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is greater than the integer, false otherwise.
            */
            friend bool operator>(const int& num, const Fraction& other) {
                return (double)num > (double)other;
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
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @return True if the current fraction is less than the double, false otherwise.
            */
            bool operator<(const double& other) const {
                return (double)*this < other;
            }

            /*
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is less than the double, false otherwise.
            */
            friend bool operator<(const double& num, const Fraction& other) {
                return num < (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the current fraction is less than the integer, false otherwise.
            */
            bool operator<(const int& other) const {
                return (double)*this < (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is less than the integer, false otherwise.
            */
            friend bool operator<(const int& num, const Fraction& other) {
                return (double)num < (double)other;
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
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @return True if the current fraction is greater than or equal to the double, false otherwise.
            */
            bool operator>=(const double& other) const {
                return (double)*this >= other;
            }

            /*
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is greater than or equal to the double, false otherwise.
            */
            friend bool operator>=(const double& num, const Fraction& other) {
                return num >= (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the current fraction is greater than or equal to the integer, false otherwise.
            */
            bool operator>=(const int& other) const {
                return (double)*this >= (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is greater than or equal to the integer, false otherwise.
            */
            friend bool operator>=(const int& num, const Fraction& other) {
                return (double)num >= (double)other;
            }

            /*
             * @brief Compares two fractions.
             * @param other The fraction to compare.
             * @return True if the current fraction is less than or equal to the other fraction, false otherwise.
            */
            bool operator<=(const Fraction& other) const {
                return (double)*this <= (double)other;
            }

            /*
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @return True if the current fraction is less than or equal to the double, false otherwise.
            */
            bool operator<=(const double& other) const {
                return (double)*this <= other;
            }

            /*
             * @brief Compares a fraction and a double.
             * @param other The double to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is less than or equal to the double, false otherwise.
            */
            friend bool operator<=(const double& num, const Fraction& other) {
                return num <= (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @return True if the current fraction is less than or equal to the integer, false otherwise.
            */
            bool operator<=(const int& other) const {
                return (double)*this <= (double)other;
            }

            /*
             * @brief Compares a fraction and an integer.
             * @param other The integer to compare.
             * @param num The fraction to compare.
             * @return True if the current fraction is less than or equal to the integer, false otherwise.
            */
            friend bool operator<=(const int& num, const Fraction& other) {
                return (double)num <= (double)other;
            }


            /************************************/
            /* Operator overload zone - Casting */
            /************************************/

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