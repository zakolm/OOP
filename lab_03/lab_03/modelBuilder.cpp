#include "modelBuilder.h"

void cModelBuilder::buildModel(std::string name)
{
    model = new cModel(name);
}

void cModelBuilder::buildPoint(std::string name, const double x, const double y, const double z)
{
    if (model)
    {
        cPoint3d point(name, x, y, z);
        model->addPoint(point);
    }
    else
        throw cBuilderNoObject();
}

void cModelBuilder::buildEdge(const int start, const int end)
{
    if (model)
    {
        cEdge edge(start, end);
        model->addEdge(edge);
    }
    else
        throw cBuilderNoObject();
}

cModel* cModelBuilder::getModel()
{
    return model;
}
