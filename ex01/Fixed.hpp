#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    private:
            int _fixedPoint;
            static const int _stockbit;
    public:
            Fixed(void);
            Fixed(const int nb);
            Fixed(const float nb);
            Fixed(const Fixed &other);
            Fixed& operator=(const Fixed &other);
            ~Fixed();

            float toFloat(void)const;
            int     toInt(void)const;      
            int getRawBits(void)const;
            void        setRawBits(int const raw);
};
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#endif