#include "absLoader.h"

cModel* cAbsLoader::loadModel(cBaseModelBuilder& builder)
{
    return loadImp->loadModel(builder);
}

void cAbsLoader::saveModel(cModel model)
{
    loadImp->saveModel(model);
}
