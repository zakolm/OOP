#include "drawerVs.h"

cDrawerVs::cDrawerVs(gcroot<System::Drawing::Graphics^> _canva, cBaseProjector* _proj)
{
    canva = _canva;
    proj = _proj;
    camera = nullptr;
}

cDrawerVs::cDrawerVs(const cDrawerVs& _drawer)
{
    canva = _drawer.canva;
}

cDrawerVs::~cDrawerVs()
{
    canva = nullptr;
}

void cDrawerVs::drawLine(const cPoint3d p1, const cPoint3d p2)
{
    if (!camera)
        throw cDrawerNoCamera();

    cMatrixDef matr = camera->getViewMatrix();
    cPoint3d p1_t = matr * p1;
    cPoint3d p2_t = matr * p2;
    cPoint2d p1_2d = proj->projectPoint(p1_t);
    cPoint2d p2_2d = proj->projectPoint(p2_t);

    canva->DrawLine(System::Drawing::Pens::Black, int(p1_2d.getX()), int(p1_2d.getY()), int(p2_2d.getX()), int(p2_2d.getY()));
}

void cDrawerVs::setCamera(cCamera* _camera)
{
    camera = _camera;
}
