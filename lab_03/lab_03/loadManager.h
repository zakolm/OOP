#pragma once

#include "baseManager.h"
#include "model.h"
#include "absLoader.h"
#include "iterator.h"

class cLoadManager: public cBaseManager
{
public:
    cLoadManager() { };
    ~cLoadManager() { };

    cModel* loadModel(cAbsLoader& loader, cBaseModelBuilder& builder);
    void saveModel(cAbsLoader& loader, objIterator start, objIterator end);
};
