#pragma once

#include "baseManager.h"
#include "model.h"
#include "drawerVs.h"
#include "iterator.h"

class cDrawManager: public cBaseManager
{
public:
    cDrawManager() { };
    ~cDrawManager() { };

    void draw(cBaseDrawer& drawer, posIterator posIter, objIterator start, objIterator end);
};
