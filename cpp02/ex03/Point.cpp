#include "Point.hpp"

Point::Point()
    : x(0), y(0)
{
}

Point::Point(const float xVal, const float yVal)
    : x(xVal), y(yVal)
{
}

Point::Point(const Point &other)
    : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point()
{
}

const Fixed& Point::getX() const
{
    return x;
}

const Fixed& Point::getY() const
{
    return y;
}

std::ostream &operator<< (std::ostream &out, const Point &p)
{
    out << "(" << p.getX() << ", " << p.getY() << ")";
    return out;
}

static float area(const Point &p1, const Point &p2, const Point &p3)
{
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    float A = area(a, b, c);
    float A1 = area(point, a, b);
    float A2 = area(point, b, c);
    float A3 = area(point, c, a);

    if (A == A1 + A2 + A3 && A1 > 0 && A2 > 0 && A3 > 0)
    {
        return true;
    }

    return false;
}
