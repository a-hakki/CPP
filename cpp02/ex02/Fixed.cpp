#include "Fixed.hpp"

Fixed::Fixed()
    : _fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

Fixed::Fixed(const int intValue)
{
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

std::ostream &operator<< (std::ostream &cout, const Fixed &obj)
{
    cout << obj.toFloat();
    return cout;
}

Fixed Fixed::operator+ (const Fixed &obj2) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + obj2._fixedPointValue);
    return result;
}

Fixed Fixed::operator- (const Fixed &obj2) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - obj2._fixedPointValue);
    return result;
}

Fixed Fixed::operator* (const Fixed &obj2) const
{
    Fixed result;
    int prod = this->_fixedPointValue * obj2._fixedPointValue;
    result.setRawBits((int)(prod >> this->_fractionalBits));
    return result;
}

Fixed Fixed::operator/ (const Fixed &obj2) const
{
    Fixed result;
    int num = (this->_fixedPointValue << this->_fractionalBits);
    result.setRawBits((int)(num / obj2._fixedPointValue));
    return result;
}

bool Fixed::operator>(const Fixed &obj) const
{
    return this->_fixedPointValue > obj._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return this->_fixedPointValue >= obj._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return this->_fixedPointValue <= obj._fixedPointValue;
}

bool Fixed::operator<(const Fixed &obj) const
{
    return this->_fixedPointValue < obj._fixedPointValue;
}

bool Fixed::operator==(const Fixed &obj) const
{
    return this->_fixedPointValue ==obj._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return this->_fixedPointValue != obj._fixedPointValue;
}

Fixed &Fixed::operator++()
{
    this->_fixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue--;
    return tmp;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

