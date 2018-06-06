#include "drawManager.h"

void cDrawManager::draw(cBaseDrawer& drawer, posIterator posIter, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++, posIter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* _model = (cModel*) (*iter);
        _model->draw(drawer, *posIter);
    }
}
