#pragma once

#include "baseModelBuilder.h"
#include "model.h"
#include "builderExceptions.h"

class cModelBuilder: public cBaseModelBuilder
{
public:
    cModelBuilder() { model = nullptr; };
    virtual void buildModel(std::string name) override;
    virtual void buildPoint(std::string name, const double x, const double y, const double z) override;
    virtual void buildEdge(const int start, const int end) override;
    virtual cModel* getModel() override;

private:
    cModel* model;
};
