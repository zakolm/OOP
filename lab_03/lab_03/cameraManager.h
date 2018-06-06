#pragma once

#include "baseManager.h"
#include "camera.h"
#include "sceneContainer.h"

class cCameraManager: public cBaseManager
{
public:
    cCameraManager() { };
    ~cCameraManager() { };

    void yaw(double y, camIterator iter);
    void pitch(double p, camIterator iter);
    void roll(double r, camIterator iter);
    
    void setPosition(cVector3d vect);
    void setTarget(cVector3d vect);
};
