#include "Fixed.hpp"

const int Fixed::_stockbit = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{
    std::cout << "Default Constractor Called" <<std::endl;
}
Fixed::Fixed(const int nb) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPoint =  nb << this->_stockbit;
}
Fixed::Fixed(const float nb)  
{
    std::cout << "Float constructor called" << std::endl;
     this->_fixedPoint =  roundf(nb * (1 << this->_stockbit));
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
    return (this->_fixedPoint);
}
void Fixed::setRawBits(int raw)
{
    this->_fixedPoint = raw;
    return ;
}   

int Fixed::toInt(void)const
{
    return  roundf(this->_fixedPoint >> this->_stockbit);
}
float Fixed::toFloat(void)const
{
    return ((float)this->_fixedPoint / (1 << this->_stockbit));
}
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}