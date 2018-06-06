#pragma once

#include <vector>
#include "obejct.h"
#include "point3d.h"
#include "edge.h"
#include "drawerVs.h"
#include "position.h"
#include "modelExceptions.h"

class cModel: public cObject
{
public:
    cModel(std::string _name);
    explicit cModel(const std::string _name, const std::vector<cPoint3d> _points, const std::vector<cEdge> _edges)
        : cObject(_name), points(_points), edges(_edges) { }
    cModel(const cModel& _model);
    cModel(cModel&& _model);
    ~cModel() { }

    bool visible();
    bool isComposite();
	void Run(){};

    void addPoint(cPoint3d point);
    void addEdge(cEdge edge);
    void removePoint(int index);
    void removeEdge(int index);

    cModel& operator =(const cModel& _model);
    cModel& operator =(cModel&& _model);

    void draw(cBaseDrawer& drawer, cPosition position);

    const std::vector<cPoint3d> getPoints() const;
    const std::vector<cEdge> getEdges() const;
    int getCountPoints() const;
    int getCountEdges() const;

	typedef void (*func_t0) (cModel &model, const double);
	typedef void (*func_t1) (cModel &model, const double, const double, const double);
	void Run(cModel &model, const double angle, func_t0 f)
    {
        f(model, angle);
    }
	void Run(cModel &model, const double x, const double y, const double z, func_t1 f)
    {
        f(model, x, y, z);
    }
	std::vector<cPoint3d> get_points()
	{
		return this->points;
	}
	std::vector<cEdge> get_edges()
	{
		return this->edges;
	}
private:
	std::vector<cPoint3d> points;
    std::vector<cEdge> edges;
};