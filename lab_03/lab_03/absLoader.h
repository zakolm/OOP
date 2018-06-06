#pragma once

#include "impLoader.h"
#include "model.h"
#include "baseModelBuilder.h"

class cAbsLoader
{
public:
    explicit cAbsLoader(cImpLoader* _loadImp)
        : loadImp(_loadImp) { }

    cModel* loadModel(cBaseModelBuilder& builder);
    void saveModel(cModel model);

private:
    cImpLoader* loadImp;
};
