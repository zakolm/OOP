#pragma once

#include <cmath>
#include "obejct.h"
#include "vector3d.h"
#include "point3d.h"
#include "matrixDef.h"

class cCamera: public cObject
{
public:
    cCamera(std::string _name);
    explicit cCamera(std::string _name, const cPoint3d _pos, const cPoint3d _target, double y, double p, double r);
    ~cCamera() { };

    bool visible();
    bool isComposite();

    void setPosition(const cPoint3d _pos);
    void setTarget(const cPoint3d _target);

    cMatrixDef getViewMatrix();

	typedef void (cCamera::*func_t) (const double);
	void Run(){};
	void Run(cCamera *pClass, const double tmp, func_t f) 
	{
		(pClass->*f)(tmp);
	}
    void yaw(const double y);
    void pitch(const double p);
    void roll(const double r);

private:
    cVector3d look;
    cVector3d up;
    cVector3d right;
    cVector3d pos;
    cVector3d target;
};
