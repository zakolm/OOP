#pragma once

#include "baseManager.h"
#include "model.h"
#include "sceneContainer.h"

class cTransformManager: public cBaseManager
{
public:
    cTransformManager() { };
    ~cTransformManager() { };

    void shiftModel(const double dx, const double dy, const double dz, objIterator start, objIterator end);

    void scaleModel(const double kx, const double ky, const double kz, objIterator start, objIterator end);

    void rotateXModel(const double angle, objIterator start, objIterator end);
    void rotateYModel(const double angle, objIterator start, objIterator end);
    void rotateZModel(const double angle, objIterator start, objIterator end);
};
