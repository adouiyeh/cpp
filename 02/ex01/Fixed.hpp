#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    private:
        int _numVal;
        static const int _fracBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int intVal);
        Fixed(const float floatVal);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif