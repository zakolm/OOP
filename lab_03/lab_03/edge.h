#pragma once

#include <iostream>

class cEdge
{
public:
    cEdge();
    cEdge(const int _start, const int _end);
    cEdge(const cEdge& _edge);
    cEdge(cEdge&& _edge);
    ~cEdge() { }
    
    int getStart() const;
    int getEnd() const;
    
    void setStart(const int _start);
    void setEnd(const int _end);
    
    cEdge& operator =(const cEdge& _edge);
    cEdge& operator =(cEdge&& _edge);

    friend std::ostream& operator <<(std::ostream& output, const cEdge& _edge);
    friend std::istream& operator >>(std::istream& input, cEdge& _edge);

private:
    int start, end;
};
