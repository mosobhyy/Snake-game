#include "Point.h"

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int x)
{
    Point::x = x;
}

void Point::setY(int y)
{
    Point::y = y;
}


bool Point::operator==(Point const &point)
{
    return (this->x == point.getX() && this->y == point.getY());
}

Point Point::operator+(Point const &point)
{
    Point result(x + point.getX(), y + point.getY());
    return result;
}

Point::Point(int x = 0, int y = 0)
{
    setX(x);
    setY(y);
}
