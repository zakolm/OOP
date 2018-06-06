#include "transformManager.h"

void Modelshift(cModel &model, const double dx, const double dy, const double dz)
{
	std::vector<cPoint3d> tmp_points = model.get_points();
	// = model.get_edges();
    if (tmp_points.empty())
        throw cModelNoPoints();
    if (model.get_edges().empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < model.get_points().size(); i++)
        tmp_points[i].shift(dx, dy, dz);
}

void Modelscale(cModel &model, const double kx, const double ky, const double kz)
{
	std::vector<cPoint3d> tmp_points = model.get_points();
    if (tmp_points.empty())
        throw cModelNoPoints();
    if (model.get_edges().empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < model.get_points().size(); i++)
        tmp_points[i].scale(kx, ky, kz);
}

void ModelrotateX(cModel &model, const double angle)
{
    if (model.get_points().empty())
        throw cModelNoPoints();
    if (model.get_edges().empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < model.get_points().size(); i++)
        model.get_points()[i].rotateX(angle);
}

void ModelrotateY(cModel &model, const double angle)
{
    if (model.get_points().empty())
        throw cModelNoPoints();
    if (model.get_edges().empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < model.get_points().size(); i++)
        model.get_points()[i].rotateY(angle);
}

void ModelrotateZ(cModel &model, const double angle)
{
    if (model.get_points().empty())
        throw cModelNoPoints();
    if (model.get_edges().empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < model.get_points().size(); i++)
        model.get_points()[i].rotateZ(angle);
}

void cTransformManager::shiftModel(const double dx, const double dy, const double dz, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);
		model->Run(*model, dx,dy,dz, Modelshift);
    }
}

void cTransformManager::scaleModel(const double kx, const double ky, const double kz, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);
		model->Run(*model, kx, ky, kz, Modelscale);
    }
}

void cTransformManager::rotateXModel(const double angle, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);
		model->Run(*model, angle, ModelrotateX);//model->rotateX(angle);
    }
}

void cTransformManager::rotateYModel(const double angle, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);
		model->Run(*model, angle, ModelrotateY);//model->rotateY(angle);
    }
}

void cTransformManager::rotateZModel(const double angle, objIterator start, objIterator end)
{
    for (objIterator iter = start; iter != end; iter++)
    {
        if (!*iter)
            throw cManagerNoTarget();

        cModel* model = (cModel*) (*iter);
        model->Run(*model, angle, ModelrotateZ);//model->rotateZ(angle);
    }
}
