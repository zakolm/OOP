#pragma once

#include "point2d.h"
#include "point3d.h"
#include "camera.h"

class cBaseDrawer
{
public:
    cBaseDrawer() { };
    virtual ~cBaseDrawer() { };

    virtual void drawLine(const cPoint3d p1, const cPoint3d p2) = 0;
    virtual void setCamera(cCamera* _camera) = 0;
};
