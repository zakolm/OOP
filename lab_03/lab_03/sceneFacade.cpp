#include "sceneFacade.h"

void cSceneFacade::addModel(cModel* _model)
{
    sceneContainer.addModel(_model);
}

void cSceneFacade::remModel(objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
        sceneContainer.remModel(iter);
}

void cSceneFacade::addCamera(cCamera* _camera)
{
    sceneContainer.addCamera(_camera);
}

void cSceneFacade::remCamera(camIterator iter)
{
    sceneContainer.remCamera(iter);
}


cCamera* cSceneFacade::getCurCamera()
{
    return sceneContainer.getCurCamera();
}

void cSceneFacade::setCurCamera(cCamera* _camera)
{
    sceneContainer.setCurCamera(_camera);
}

cSceneContainer& cSceneFacade::getSceneContainer()
{
    return sceneContainer;
}

cTransformManager& cSceneFacade::getTransformManager()
{
    return transformManager;
}

cDrawManager& cSceneFacade::getDrawManager()
{
    return drawManager;
}

cLoadManager& cSceneFacade::getLoadManager()
{
    return loadManager;
}

cCameraManager& cSceneFacade::getCameraManager()
{
    return cameraManager;
}

objIterator cSceneFacade::createObjIterator(std::string name)
{
    objIterator iter = sceneContainer.objBegin();
    for (; iter != sceneContainer.objEnd() && (*iter)->getName() != name; iter++);

    if (iter == sceneContainer.objEnd())
        throw cFacadeNoObjIterator();

    return iter;
}

camIterator cSceneFacade::createCamIterator(std::string name)
{
    camIterator iter = sceneContainer.camBegin();
    for (; iter != sceneContainer.camEnd() && (*iter)->getName() != name; iter++);

    if (iter == sceneContainer.camEnd())
        throw cFacadeNoObjIterator();

    return iter;
}
