#include "point2d.h"

cPoint2d::cPoint2d()
{
    x = 0;
    y = 0;
}

cPoint2d::cPoint2d(const double _x, const double _y)
{
    x = _x;
    y = _y;
}

cPoint2d::cPoint2d(const cPoint2d& _point)
{
    x = _point.x;
    y = _point.y;
}

cPoint2d::cPoint2d(const cPoint2d&& _point)
{
    x = _point.x;
    y = _point.y;
    _point.~cPoint2d();
}

void cPoint2d::setX(const double _x)
{
    x = _x;
}

void cPoint2d::setY(const double _y)
{
    y = _y;
}

double cPoint2d::getX() const
{
    return x;
}

double cPoint2d::getY() const
{
    return y;
}

cPoint2d& cPoint2d::operator =(const cPoint2d& _point)
{
    x = _point.x;
    y = _point.y;

    return *this;
}

cPoint2d& cPoint2d::operator =(cPoint2d&& _point)
{
    x = _point.x;
    y = _point.y;
    _point.~cPoint2d();

    return *this;
}

std::ostream& operator <<(std::ostream& output, const cPoint2d& _point)
{
    output << _point.getX() << " ; " << _point.getY() << std::endl;

    return output;
}

std::istream& operator >>(std::istream& input, cPoint2d& _point)
{
    double x, y;
    input >> x >> y;
    
    _point.setX(x);
    _point.setY(y);

    return input;
}
