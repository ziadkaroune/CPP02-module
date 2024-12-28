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
            
            bool operator>(Fixed fixed)const;
	    bool operator<(Fixed fixed)const;
	    bool operator>=(Fixed fixed)const;
	    bool operator<=(Fixed fixed)const;
	    bool operator==(Fixed fixed)const;
	    bool operator!=(Fixed fixed)const;

           float operator+(Fixed fixed)const;
	  float operator-(Fixed fixed)const;
          float operator*(Fixed fixed)const;
	  float operator/(Fixed fixed)const;

          		 
		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);


            float toFloat(void)const;
            int     toInt(void)const;      
            int getRawBits(void)const;
            void        setRawBits(int const raw);
};
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#endif