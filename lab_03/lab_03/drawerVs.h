#pragma once

#include <gcroot.h>
#include "point3d.h"
#include "baseProjector.h"
#include "baseDrawer.h"
#include "drawerExceptions.h"

class cDrawerVs: public cBaseDrawer
{
public:
    cDrawerVs(gcroot<System::Drawing::Graphics^> _canva, cBaseProjector* _proj);
    cDrawerVs(const cDrawerVs& _drawer);
    ~cDrawerVs();

    void drawLine(const cPoint3d p1, const cPoint3d p2);
    void setCamera(cCamera* _camera);

private:
    gcroot<System::Drawing::Graphics^> canva;
    cBaseProjector* proj;
    cCamera* camera;
};
