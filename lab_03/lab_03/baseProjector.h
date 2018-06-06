#pragma once

#include "point2d.h"
#include "point3d.h"

class cBaseProjector
{
public:
    cBaseProjector() { };

    virtual cPoint2d projectPoint(cPoint3d point) = 0;
};
