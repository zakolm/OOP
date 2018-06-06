#include "sceneContainer.h"

cSceneContainer::~cSceneContainer()
{
    for (size_t i = 0; i < objects.size(); i++)
        delete objects[i];

    for (size_t i = 0; i < cameras.size(); i++)
        delete cameras[i];
}

void cSceneContainer::addModel(cModel* _model)
{
    objects.push_back(_model);
    positions.push_back(cPosition());
}

void cSceneContainer::remModel(objIterator iter)
{
    cModel* model = (cModel*) (*iter);
    delete model;
    objects.erase(iter);
}

void cSceneContainer::addCamera(cCamera* _camera)
{
    cameras.push_back(_camera);
    if (!curCamera)
        curCamera = _camera;
}

void cSceneContainer::remCamera(camIterator iter)
{
    cCamera* camera = (cCamera*) (*iter);
    delete camera;
    cameras.erase(iter);
}

cCamera* cSceneContainer::getCurCamera()
{
    return curCamera;
}

void cSceneContainer::setCurCamera(cCamera* _curCamera)
{
    curCamera = _curCamera;
}

size_t cSceneContainer::getCountObj()
{
    return objects.size();
}

size_t cSceneContainer::getCountCam()
{
    return cameras.size();
}

objIterator cSceneContainer::objBegin()
{
    return objects.begin();
}

objIterator cSceneContainer::objEnd()
{
    return objects.end();
}

camIterator cSceneContainer::camBegin()
{
    return cameras.begin();
}

camIterator cSceneContainer::camEnd()
{
    return cameras.end();
}

posIterator cSceneContainer::posBegin()
{
    return positions.begin();
}

posIterator cSceneContainer::posEnd()
{
    return positions.end();
}
