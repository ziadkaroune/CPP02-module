#include "Fixed.hpp"

const int Fixed::_stockbit = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    std::cout << "Default Constractor Called" <<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "copyConstractor Called" <<std::endl;
    _fixedPoint = other._fixedPoint;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
      std::cout << "Copy assigned  operator Called" <<std::endl;
    if(this != &other)
        this->_fixedPoint = other.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destractor Called" <<std::endl;
}

int Fixed::getRawBits(void)const
{
     std::cout << "getRawBits member function called" <<std::endl;
    return (this->_fixedPoint);
}
void Fixed::setRawBits(int raw)
{
    this->_fixedPoint = raw;
    return ;
}   
