#pragma once

#include "baseModelBuilder.h"
#include "model.h"

class cImpLoader
{
public:
    cImpLoader() { }
    virtual ~cImpLoader() { }

    virtual cModel* loadModel(cBaseModelBuilder& builder) = 0;
    virtual void saveModel(cModel model) = 0;
};
