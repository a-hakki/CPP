#ifndef FIXED_HPP
# define FIXED_HPP 
# include <iostream>
# include <cmath>


class Fixed {
   private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(int const raw);
    int     toInt( void ) const;
    float   toFloat( void ) const;
};

std::ostream &operator<< (std::ostream &cout, const Fixed &obj);

#endif // FIXED_HPP cout << fixed