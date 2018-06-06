#include "model.h"

cModel::cModel(std::string _name)
    : cObject(_name)
{

}

cModel::cModel(const cModel& _model)
    : cObject(_model.objName)
{
    points = _model.points;
    edges = _model.edges;
}

cModel::cModel(cModel&& _model)
    : cObject(_model.objName)
{
    points = _model.points;
    edges = _model.edges;
    _model.~cModel();
}

bool cModel::visible()
{
    return true;
}

bool cModel::isComposite()
{
    return false;
}

void cModel::addPoint(cPoint3d point)
{
    points.push_back(point);
}

void cModel::addEdge(cEdge edge)
{
    edges.push_back(edge);
}

void cModel::removePoint(int index)
{
    if (points.empty())
        throw cModelNoPoints();

    points.erase(points.begin() + index);
}

void cModel::removeEdge(int index)
{
    if (edges.empty())
        throw cModelNoEdges();

    edges.erase(edges.begin() + index);
}

cModel& cModel::operator =(const cModel& _model)
{
    points = _model.points;
    edges = _model.edges;

    return *this;
}

cModel& cModel::operator =(cModel&& _model)
{
    points = _model.points;
    edges = _model.edges;
    _model.~cModel();

    return *this;
}

void cModel::draw(cBaseDrawer& drawer, cPosition position)
{
    if (points.empty())
        throw cModelNoPoints();
    if (edges.empty())
        throw cModelNoEdges();

    for (size_t i = 0; i < edges.size(); i++)
    {
        cPoint3d p1 = points[edges[i].getStart()];
        cPoint3d p2 = points[edges[i].getEnd()];
        
		/*p1.Run(position.pos[0], position.pos[1], position.pos[2]);*/p1.shift(position.pos[0], position.pos[1], position.pos[2]);
        p2.shift(position.pos[0], position.pos[1], position.pos[2]);
        
        p1.rotateX(position.orientation[0]);
        p2.rotateX(position.orientation[0]);

        p1.rotateY(position.orientation[1]);
        p2.rotateY(position.orientation[1]);
        
        p1.rotateZ(position.orientation[2]);
        p2.rotateZ(position.orientation[2]);

        drawer.drawLine(p1, p2);
    }
}

const std::vector<cPoint3d> cModel::getPoints() const
{
    return points;
}

const std::vector<cEdge> cModel::getEdges() const
{
    return edges;
}

int cModel::getCountPoints() const
{
    return points.size();
}

int cModel::getCountEdges() const
{
    return edges.size();
}
