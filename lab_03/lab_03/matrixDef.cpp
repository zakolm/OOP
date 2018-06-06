#include "matrixDef.h"

cMatrixDef::cMatrixDef()
{
    matr = std::vector<std::vector<double>>(COUNT_ROW);
    for (int i = 0; i < COUNT_ROW; i++)
        matr[i] = std::vector<double>(COUNT_COL);
}

cMatrixDef::cMatrixDef(const cMatrixDef& _matr)
{
    matr = _matr.matr;
}

cMatrixDef::cMatrixDef(cMatrixDef&& _matr)
{
    matr = _matr.matr;
    _matr.~cMatrixDef();
}

cMatrixDef& cMatrixDef::operator =(const cMatrixDef& _matr)
{
    matr = _matr.matr;

    return *this;
}

cMatrixDef& cMatrixDef::operator =(cMatrixDef&& _matr)
{
    matr = _matr.matr;
    _matr.~cMatrixDef();

    return *this;
}

std::vector<double> cMatrixDef::operator [](int index)
{
    return matr[index];
}

cVector3d cMatrixDef::operator *(const cVector3d& _vector)
{
    cVector3d result;
    result[3] = 0;

    for (int i = 0; i < COUNT_ROW; i++)
        for (int j = 0; j < COUNT_COL; j++)
            result[i] += matr[i][j] * _vector[j];

    return result;
}

cMatrixDef cMatrixDef::operator *(const double num)
{
    cMatrixDef _matr(*this);

    for (int i = 0; i < COUNT_ROW; i++)
        for (int j = 0; j < COUNT_COL; j++)
            _matr[i][j] *= num;

    return _matr;
}

cPoint3d cMatrixDef::operator *(const cPoint3d& point)
{
    cVector3d vector = point.toVector3d();
    cVector3d result;
    result[3] = 0;

    for (int i = 0; i < COUNT_ROW; i++)
        for (int j = 0; j < COUNT_COL; j++)
            result[i] += matr[i][j] * vector[j];

    return cPoint3d("tmppoint", result[0], result[1], result[2]);
}
