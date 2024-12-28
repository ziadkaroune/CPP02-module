#include "Fixed.hpp"

const int Fixed::_stockbit = 8;

Fixed::Fixed(void) : _fixedPoint(0)
{

}
Fixed::Fixed(const int nb) 
{
 
    this->_fixedPoint =  nb << this->_stockbit;
}
Fixed::Fixed(const float nb)  
{
 
     this->_fixedPoint =  roundf(nb * (1 << this->_stockbit));
}
Fixed::Fixed(const Fixed &other)
{
 
    _fixedPoint = other._fixedPoint;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
 
    if(this != &other)
        this->_fixedPoint = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(Fixed fixed)const
{
   return (this->toFloat() > fixed.toFloat());
}
bool Fixed::operator<(Fixed fixed)const
{
   return (this->toFloat() < fixed.toFloat());
}
bool Fixed::operator<=(Fixed fixed)const
{
   return (this->toFloat() <=fixed.toFloat());
}
bool Fixed::operator>=(Fixed fixed)const
{
   return (this->toFloat() >= fixed.toFloat());
}
bool Fixed::operator==(Fixed fixed)const
{
   return (this->toFloat() == fixed.toFloat());
}
bool Fixed::operator!=(Fixed fixed)const
{
   return (this->toFloat() != fixed.toFloat());
}


float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
return (this->toFloat() / fixed.toFloat());
}




Fixed&	Fixed::operator++()
{
	this->_fixedPoint++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_fixedPoint--;
	return (*this);
}

 
Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this; 
	++this->_fixedPoint;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this; 
	--this->_fixedPoint;
	return (tmp);
}


Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
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
Fixed::~Fixed()
{
    
}
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}