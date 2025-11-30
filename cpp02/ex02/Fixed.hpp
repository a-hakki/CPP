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
    Fixed &operator=(const Fixed& other);
    ~Fixed();
    // arithmetic operations
    Fixed operator+ (const Fixed &obj) const;
    Fixed operator- (const Fixed &obj) const;
    Fixed operator* (const Fixed &obj) const;
    Fixed operator/ (const Fixed &obj) const;
    // comparison operations
    bool operator> (const Fixed &obj) const;
    bool operator>= (const Fixed &obj) const;
    bool operator<= (const Fixed &obj) const;
    bool operator< (const Fixed &obj) const;
    bool operator== (const Fixed &obj) const;
    bool operator!= (const Fixed &obj) const;
    //The 4 increment/decrement
    Fixed &operator++ ();
    Fixed &operator-- ();
    Fixed operator++ (int);
    Fixed operator-- (int);

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    int     toInt( void ) const;
    float   toFloat( void ) const;
};

std::ostream &operator<< (std::ostream &cout, const Fixed &obj);

#endif // FIXED_HPP cout << fixed