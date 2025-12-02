 #ifndef Point_HPP
 # define Point_HPP 
 # include "Fixed.hpp"
 # include <iostream>


class Point {
    private:
        const Fixed   x;
        const Fixed   y;

    public:
        Point();
        Point(const float xVal, const float yVal);
        Point(const Point& other);
        Point &operator=(const Point& other);
        ~Point();

        const Fixed& getX() const;
        const Fixed& getY() const;
};

std::ostream &operator<< (std::ostream &out, const Point &p);

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif // Point_HPP