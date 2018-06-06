#pragma once

#include <vector>
#include "obejct.h"
#include "model.h"
#include "camera.h"
#include "drawerVs.h"
#include "position.h"
#include "iterator.h"

class cSceneContainer
{
public:
    cSceneContainer() { curCamera = nullptr; };
    ~cSceneContainer();

    void addModel(cModel* _model);
    void remModel(objIterator iter);

    void addCamera(cCamera* _camera);
    void remCamera(camIterator iter);

    cCamera* getCurCamera();
    void setCurCamera(cCamera* _curCamera);

    size_t getCountObj();
    size_t getCountCam();

    objIterator objBegin();
    objIterator objEnd();

    camIterator camBegin();
    camIterator camEnd();

    posIterator posBegin();
    posIterator posEnd();

protected:

private:
    std::vector<cObject*> objects;
    std::vector<cPosition> positions;
    std::vector<cCamera*> cameras;

    cCamera* curCamera;
};
