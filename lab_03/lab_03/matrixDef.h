#pragma once

#include <vector>
#include "vector3d.h"
#include "point3d.h"

#define COUNT_ROW 4
#define COUNT_COL 4
#define SIZE 16

class cMatrixDef
{
public:
    cMatrixDef();
    cMatrixDef(const cMatrixDef& _matr);
    cMatrixDef(cMatrixDef&& _matr);
    ~cMatrixDef() { }
    
    cMatrixDef& operator =(const cMatrixDef& _matr);
    cMatrixDef& operator =(cMatrixDef&& _matr);

    std::vector<double> operator [](int index);

    cVector3d operator *(const cVector3d& _vector);
    cMatrixDef operator *(const double num);
    cPoint3d operator *(const cPoint3d& point);

    void setNum(int i, int j, double num)
    {
        matr[i][j] = num;
    }

private:
    std::vector<std::vector<double>> matr;
};
