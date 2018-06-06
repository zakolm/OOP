#include "edge.h"

cEdge::cEdge()
{
    start = 0;
    end = 0;
}

cEdge::cEdge(const int _start, const int _end)
{
    start = _start;
    end = _end;
}

cEdge::cEdge(const cEdge& _edge)
{
    start = _edge.start;
    end = _edge.end;
}

cEdge::cEdge(cEdge&& _edge)
{
    start = _edge.start;
    end = _edge.end;
    _edge.~cEdge();
}

int cEdge::getStart() const
{
    return start;
}

int cEdge::getEnd() const
{
    return end;
}

void cEdge::setStart(const int _start)
{
    start = _start;
}

void cEdge::setEnd(const int _end)
{
    end = _end;
}

cEdge& cEdge::operator =(const cEdge& _edge)
{
    start = _edge.start;
    end = _edge.end;

    return *this;
}

cEdge& cEdge::operator =(cEdge&& _edge)
{
    start = _edge.start;
    end = _edge.end;
    _edge.~cEdge();

    return *this;
}

std::ostream& operator <<(std::ostream& output, const cEdge& _edge)
{
    output << _edge.getStart() << " - " << _edge.getEnd() << std::endl;

    return output;
}

std::istream& operator >>(std::istream& input, cEdge& _edge)
{
    int m, n;
    input >> m;
    input >> n;
    
    _edge.setStart(m);
    _edge.setEnd(n);

    return input;
}
