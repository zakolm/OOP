#pragma once

#include <vector>
#include <cmath>

class cVector3d
{
public:
    cVector3d();
    cVector3d(const double x, const double y, const double z);
    cVector3d(const cVector3d& _vector);
    cVector3d(cVector3d&& _vector);
    ~cVector3d() { };

    cVector3d& operator =(const cVector3d& _vector);
    cVector3d& operator =(cVector3d&& _vector);

    double& operator [](const int index);
    const double& operator [](const int index) const;
    
    double getX() const;
    double getY() const;
    double getZ() const;
    
    void setX(const double x);
    void setY(const double y);
    void setZ(const double z);

    double module() const;
    void normalize();

    friend double scalarMul(const cVector3d& a, const cVector3d& b);
    friend double angle(const cVector3d& a, const cVector3d& b);
    friend cVector3d vectMul(const cVector3d& a, const cVector3d& b);

private:
    std::vector<double> vector;
};
