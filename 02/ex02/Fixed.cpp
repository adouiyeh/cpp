#include "Fixed.hpp"

Fixed::Fixed() : _numVal(0) {}

Fixed::Fixed(const int intVal)
{
    _numVal = intVal << _fracBits;
}

Fixed::Fixed(const float floatVal)
{
    _numVal = (int)roundf(floatVal * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _numVal = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return _numVal;
}

void Fixed::setRawBits(int const raw)
{
    _numVal = raw;
}

int Fixed::toInt(void) const
{
    return (_numVal >> _fracBits);
}

float Fixed::toFloat(void) const
{
    return ((float)_numVal / (1 << _fracBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& other) const {
    return _numVal > other._numVal;
}

bool Fixed::operator<(const Fixed& other) const {
    return _numVal < other._numVal;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _numVal >= other._numVal;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _numVal <= other._numVal;
}

bool Fixed::operator==(const Fixed& other) const {
    return _numVal == other._numVal;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _numVal != other._numVal;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    ++_numVal;
    return *this;
}

Fixed& Fixed::operator--()
{
    --_numVal;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _numVal++;
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _numVal--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
