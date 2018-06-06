#pragma once

#include <string>
#include "sceneContainer.h"
#include "loadManager.h"
#include "transformManager.h"
#include "drawManager.h"
#include "cameraManager.h"
#include "facadeExceptions.h"

class cSceneFacade
{
public:
    cSceneFacade() { };
    ~cSceneFacade() { };

    void addModel(cModel* _model);
    void remModel(objIterator start, objIterator end);
    void addCamera(cCamera* _camera);
    void remCamera(camIterator iter);

    cCamera* getCurCamera();
    void setCurCamera(cCamera* _camera);

    cSceneContainer& getSceneContainer();
    cTransformManager& getTransformManager();
    cDrawManager& getDrawManager();
    cLoadManager& getLoadManager();
    cCameraManager& getCameraManager();

    objIterator createObjIterator(std::string name);
    camIterator createCamIterator(std::string name);

private:
    cSceneContainer sceneContainer;
    cTransformManager transformManager;
    cDrawManager drawManager;
    cLoadManager loadManager;
    cCameraManager cameraManager;
};
