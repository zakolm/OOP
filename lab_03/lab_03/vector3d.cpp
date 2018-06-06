#include "vector3d.h"

cVector3d::cVector3d()
{
    vector = std::vector<double>(4, 0);
    vector[3] = 1;
}

cVector3d::cVector3d(const double x, const double y, const double z)
{
    vector = std::vector<double>(4, 0);
    vector[0] = x;
    vector[1] = y;
    vector[2] = z;
    vector[3] = 1;
}

cVector3d::cVector3d(const cVector3d& _vector)
{
    vector = _vector.vector;
}

cVector3d::cVector3d(cVector3d&& _vector)
{
    vector = _vector.vector;
    _vector.~cVector3d();
}

cVector3d& cVector3d::operator =(const cVector3d& _vector)
{
    vector = _vector.vector;

    return *this;
}

cVector3d& cVector3d::operator =(cVector3d&& _vector)
{
    vector = _vector.vector;
    _vector.~cVector3d();

    return *this;
}

double& cVector3d::operator [](const int index)
{
    return vector[index];
}

const double& cVector3d::operator [](const int index) const
{
    return vector[index];
}

double cVector3d::getX() const
{
    return vector[0];
}

double cVector3d::getY() const
{
    return vector[1];
}

double cVector3d::getZ() const
{
    return vector[2];
}


void cVector3d::setX(const double x)
{
    vector[0] = x;
}

void cVector3d::setY(const double y)
{
    vector[1] = y;
}

void cVector3d::setZ(const double z)
{
    vector[2] = z;
}


double cVector3d::module() const
{
    return sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
}

void cVector3d::normalize()
{
    double norm = pow(this->module(), -1);
    
    vector[0] *= norm;
    vector[1] *= norm;
    vector[2] *= norm;
}

double scalarMul(const cVector3d& a, const cVector3d& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double angle(const cVector3d& a, const cVector3d& b)
{
    double mod = a.module() * b.module();
    return scalarMul(a, b) / mod;
}

cVector3d vectMul(const cVector3d& a, const cVector3d& b)
{
    cVector3d c;

    c[0] = a[2] * b[1] - a[1] * b[2];
    c[1] = a[0] * b[2] - a[2] * b[0];
    c[2] = a[1] * b[0] - a[0] * b[1];

    return c;
}
