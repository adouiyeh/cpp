#include "Fixed.hpp"

Fixed::Fixed() : _numVal(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
{
    std::cout << "Int constructor called" << std::endl;
    _numVal = intVal << _fracBits;
}

Fixed::Fixed(const float floatVal)
{
    std::cout << "Float constructor called" << std::endl;
    _numVal = (int)roundf(floatVal * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _numVal = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _numVal;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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
