#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include "obejct.h"
#include "vector3d.h"

class cPoint3d: public cObject
{
public:
    cPoint3d(std::string _name);
    explicit cPoint3d(std::string _name, const double _x, const double _y, const double _z);
    cPoint3d(const cPoint3d& _point);
    cPoint3d(cPoint3d&& _point);
    ~cPoint3d() { };

    bool visible();
    bool isComposite();
    
    void setX(const double _x);
    void setY(const double _y);
    void setZ(const double _z);
    
    double getX() const;
    double getY() const;
    double getZ() const;

    cVector3d toVector3d() const;

	void Run(){};
	void Run(const double dx, const double dy, const double dz, void (*f)(const double dx, const double dy, const double dz))
	{
		f(x, y, z);
	}
	void Run(const double angle, void (*f)(const double angle))
	{
		f(angle);
	}
    void shift(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotateX(const double angle);
    void rotateY(const double angle);
    void rotateZ(const double angle);

    cPoint3d& operator =(const cPoint3d& _point);
    cPoint3d& operator =(cPoint3d&& _point);
    
    friend std::ostream& operator <<(std::ostream& output, const cPoint3d& _point);
    friend std::istream& operator >>(std::istream& input, cPoint3d& _point);

    double gradToRad(const double angle);

private:
    double x, y, z;
};
