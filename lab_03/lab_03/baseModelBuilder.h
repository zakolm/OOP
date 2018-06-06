#pragma once

#include "model.h"

class cBaseModelBuilder
{
public:
    cBaseModelBuilder() { }
    virtual ~cBaseModelBuilder() { }

    virtual void buildModel(std::string name) = 0;
    virtual void buildPoint(std::string name, const double x, const double y, const double z) = 0;
    virtual void buildEdge(const int start, const int end) = 0;
    virtual cModel* getModel() = 0;
};
