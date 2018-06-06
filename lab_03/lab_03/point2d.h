#pragma once

#include <iostream>

class cPoint2d
{
public:
    explicit cPoint2d();
    explicit cPoint2d(const double _x, const double _y);
    cPoint2d(const cPoint2d& _point);
    cPoint2d(const cPoint2d&& _point);
    ~cPoint2d() { }
    
    void setX(const double _x);
    void setY(const double _y);
    
    double getX() const;
    double getY() const;
    
    cPoint2d& operator =(const cPoint2d& _point);
    cPoint2d& operator =(cPoint2d&& _point);
    
    friend std::ostream& operator <<(std::ostream& output, const cPoint2d& _point);
    friend std::istream& operator >>(std::istream& input, cPoint2d& _point);

private:
    double x, y;
};
