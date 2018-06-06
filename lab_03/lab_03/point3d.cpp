#include "point3d.h"

cPoint3d::cPoint3d(std::string _name)
    : cObject(_name)
{
    x = 0;
    y = 0;
    z = 0;
}

cPoint3d::cPoint3d(std::string _name, const double _x, const double _y, const double _z)
    : cObject(_name)
{
    x = _x;
    y = _y;
    z = _z;
}

cPoint3d::cPoint3d(const cPoint3d& _point)
    : cObject(_point.objName)
{
    x = _point.x;
    y = _point.y;
    z = _point.z;
}

cPoint3d::cPoint3d(cPoint3d&& _point)
    : cObject(_point.objName)
{
    x = _point.x;
    y = _point.y;
    z = _point.z;
    _point.~cPoint3d();
}

bool cPoint3d::visible()
{
    return true;
}

bool cPoint3d::isComposite()
{
    return false;
}

void cPoint3d::setX(const double _x)
{
    x = _x;
}

void cPoint3d::setY(const double _y)
{
    y = _y;
}

void cPoint3d::setZ(const double _z)
{
    z = _z;
}

double cPoint3d::getX() const
{
    return x;
}

double cPoint3d::getY() const
{
    return y;
}

double cPoint3d::getZ() const
{
    return z;
}

cVector3d cPoint3d::toVector3d() const
{
    return cVector3d(x, y, z);
}

void cPoint3d::shift(const double dx, const double dy, const double dz)
{
    x += dx;
    y += dy;
    z += dz;
}

void cPoint3d::scale(const double kx, const double ky, const double kz)
{
    x *= kx;
    y *= ky;
    z *= kz;
}

void cPoint3d::rotateX(const double angle)
{
    double angleRad = gradToRad(angle);
    double angleCos = cos(angleRad);
    double angleSin = sin(angleRad);

    double y_t = y;
    double z_t = z;

    y = angleCos * y_t - angleSin * z_t;
    z = angleSin * y_t + angleCos * z_t;
}

void cPoint3d::rotateY(const double angle)
{
    double angleRad = gradToRad(angle);
    double angleCos = cos(angleRad);
    double angleSin = sin(angleRad);

    double x_t = x;
    double z_t = z;

    x = angleCos * x_t + angleSin * z_t;
    z = -angleSin * x_t + angleCos * z_t;
}

void cPoint3d::rotateZ(const double angle)
{
    double angleRad = gradToRad(angle);
    double angleCos = cos(angleRad);
    double angleSin = sin(angleRad);

    double x_t = x;
    double y_t = y;
    
    x = angleCos * x_t - angleSin * y_t;
    y = angleSin * x_t + angleCos * y_t;
}

cPoint3d& cPoint3d::operator =(const cPoint3d& _point)
{
    x = _point.x;
    y = _point.y;
    z = _point.z;

    return *this;
}

cPoint3d& cPoint3d::operator =(cPoint3d&& _point)
{
    x = _point.x;
    y = _point.y;
    z = _point.z;
    _point.~cPoint3d();

    return *this;
}

std::ostream& operator <<(std::ostream& output, const cPoint3d& _point)
{
    output << _point.getX() << " ; " << _point.getY() << " ; " << _point.getZ() << std::endl;

    return output;
}

std::istream& operator >>(std::istream& input, cPoint3d& _point)
{
    double x, y, z;
    input >> x >> y >> z;
    
    _point.setX(x);
    _point.setY(y);
    _point.setZ(z);

    return input;
}

double cPoint3d::gradToRad(const double angle)
{
    return M_PI * angle / 180;
}
