#include "camera.h"

cCamera::cCamera(std::string _name)
    : cObject(_name)
{
    right.setX(1);
    up.setY(1);
    look.setZ(1);
}

cCamera::cCamera(std::string _name, const cPoint3d _pos, const cPoint3d _target, double y, double p, double r)
    : cObject(_name)
{
    pos = _pos.toVector3d();
    target = _target.toVector3d();
    yaw(y);
    pitch(p);
    roll(r);
}

bool cCamera::visible()
{
    return false;
}

bool cCamera::isComposite()
{
    return false;
}

void cCamera::setPosition(const cPoint3d _pos)
{
    pos = _pos.toVector3d();
}

void cCamera::setTarget(const cPoint3d _target)
{
    target = _target.toVector3d();
}

cMatrixDef cCamera::getViewMatrix()
{
    look.normalize();

    up = vectMul(look, right);
    up.normalize();

    right = vectMul(up, look);
    right.normalize();

    const double x = -scalarMul(right, pos);
    const double y = -scalarMul(up, pos);
    const double z = -scalarMul(look, pos);

    cMatrixDef res;
    
    res.setNum(0, 0, right[0]); res.setNum(0, 1, up[0]); res.setNum(0, 2, look[0]); res.setNum(0, 3, 0);
    res.setNum(1, 0, right[1]); res.setNum(1, 1, up[1]); res.setNum(1, 2, look[1]); res.setNum(1, 3, 0);
    res.setNum(2, 0, right[2]); res.setNum(2, 1, up[2]); res.setNum(2, 2, look[2]); res.setNum(2, 3, 0);
    res.setNum(3, 0, x); res.setNum(3, 1, y); res.setNum(3, 2, z); res.setNum(3, 3, 1);

    return res;
}

void cCamera::yaw(const double y)
{
    cMatrixDef transform;

    double cosY = cos(y);
    double sinY = sin(y);

    transform[0][0] = cosY + (1 - cosY) * pow(up.getX(), 2);
    transform[0][1] = (1 - cosY) * up.getY() * up.getX() + sinY * up.getZ();
    transform[0][2] = (1 - cosY) * up.getZ() * up.getX() - sinY * up.getY();
    transform[0][3] = (1 - cosY) * up.getX() * up.getY() - sinY * up.getZ();
    transform[1][0] = cosY + (1 - cosY) * pow(up.getY(), 2);
    transform[1][1] = (1 - cosY) * up.getZ() * up.getY() + sinY * up.getX();
    transform[1][2] = (1 - cosY) * up.getX() * up.getZ() + sinY * up.getY();
    transform[1][3] = (1 - cosY) * up.getY() * up.getZ() - sinY * up.getX();
    transform[2][0] = cosY + (1 - cosY) * pow(up.getZ(), 2);

    right = transform * right;
    look = transform * look;
}

void cCamera::pitch(const double p)
{
    cMatrixDef transform;

    double cosP = cos(p);
    double sinP = sin(p);

    transform[0][0] = cosP + (1 - cosP) * pow(right.getX(), 2);
    transform[0][1] = (1 - cosP) * right.getY() * right.getX() + sinP * right.getZ();
    transform[0][2] = (1 - cosP) * right.getZ() * right.getX() - sinP * right.getY();
    transform[0][3] = (1 - cosP) * right.getX() * right.getY() - sinP * right.getZ();
    transform[1][0] = cosP + (1 - cosP) * pow(right.getY(), 2);
    transform[1][1] = (1 - cosP) * right.getZ() * right.getY() + sinP * right.getX();
    transform[1][2] = (1 - cosP) * right.getX() * right.getZ() + sinP * right.getY();
    transform[1][3] = (1 - cosP) * right.getY() * right.getZ() - sinP * right.getX();
    transform[2][0] = cosP + (1 - cosP) * pow(right.getZ(), 2);

    up = transform * up;
    look = transform * look;
}

void cCamera::roll(const double r)
{
    cMatrixDef transform;

    double cosR = cos(r);
    double sinR = sin(r);

    transform[0][0] = cosR + (1 - cosR) * pow(look.getX(), 2);
    transform[0][1] = (1 - cosR) * look.getY() * look.getX() + sinR * look.getZ();
    transform[0][2] = (1 - cosR) * look.getZ() * look.getX() - sinR * look.getY();
    transform[0][3] = (1 - cosR) * look.getX() * look.getY() - sinR * look.getZ();
    transform[1][0] = cosR + (1 - cosR) * pow(look.getY(), 2);
    transform[1][1] = (1 - cosR) * look.getZ() * look.getY() + sinR * look.getX();
    transform[1][2] = (1 - cosR) * look.getX() * look.getZ() + sinR * look.getY();
    transform[1][3] = (1 - cosR) * look.getY() * look.getZ() - sinR * look.getX();
    transform[2][0] = cosR + (1 - cosR) * pow(look.getZ(), 2);
    
    right = transform * right;
    up = transform * up;
}
