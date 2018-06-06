#pragma once

#include "obejct.h"
#include "iterator.h"
#include <vector>

class cCompositeObject: public cObject
{
public:
    cCompositeObject(std::string name)
        : cObject(name) { }
    virtual ~cCompositeObject() { }
    
    bool visible();
    bool isComposite();

    void addObject(cObject* _object);
    void remObject(objIterator iter);
    
private:
    std::vector<cObject*> objects;
};
