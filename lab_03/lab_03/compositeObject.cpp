#include "compositeObject.h"

bool cCompositeObject::visible()
{
    bool _visible = false;

    for (int i = 0; i < objects.size() && !_visible; i++)
        _visible = objects[i]->visible();

    return _visible;
}

bool cCompositeObject::isComposite()
{
    return true;
}

void cCompositeObject::addObject(cObject* _object)
{
    objects.push_back(_object);
}

void cCompositeObject::remObject(objIterator iter)
{
    cObject* model = (cObject*) (*iter);
    delete model;
    objects.erase(iter);
}
