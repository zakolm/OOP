#include "loadManager.h"

cModel* cLoadManager::loadModel(cAbsLoader& loader, cBaseModelBuilder& builder)
{
    cModel* model = loader.loadModel(builder);
    return model;
}

void cLoadManager::saveModel(cAbsLoader& loader, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);

        loader.saveModel(*model);
    }
}
