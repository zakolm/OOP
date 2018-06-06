#pragma once

#include "baseProjector.h"

class cMyProjector: public cBaseProjector
{
public:
    cMyProjector() { };

    virtual cPoint2d projectPoint(cPoint3d point) override
    {
        return cPoint2d(point.getX(), -point.getY());
    }
};
