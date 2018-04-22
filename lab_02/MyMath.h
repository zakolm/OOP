//
// Created by Максим on 18.04.2018.
//

#ifndef OOP_LAB_02_MYMATH_H
#define OOP_LAB_02_MYMATH_H

#include "Matrix.h"

// Сравнение матриц
template <class T>
bool Matrix<T>::IsEqual(const Matrix<T>& matrix) const
{
    if (this->GetRows() == matrix.GetRows() && this->GetColumns() == matrix.GetColumns())
        return true;
    else
        return false;
}
template <class T>
bool Matrix<T>::operator==(const Matrix<T> &matrix) const
{
    return this->IsEqual(matrix);
}
template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &matrix) const
{
    return !(this->IsEqual(matrix));
}

// Сложение матриц
template <class T>
Matrix<T> add(const Matrix<T>& A, const Matrix<T>& B)
{
    if (A.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(A).name(), __LINE__ - 4, ctime(&t_time), "Matrix A is Empty");
    }
    if (B.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(B).name(), __LINE__ - 4, ctime(&t_time), "Matrix B is Empty");
    }
    if (A != B)
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsNotEqualException(__FILE__, typeid(A).name(), __LINE__ - 4, ctime(&t_time), "Matrix A != B");
    }
    Matrix<T> C = A;
    for (size_t i = 0; i < B.GetRows(); ++i)
        for (size_t j = 0; j < B.GetColumns(); ++j)
            C[i][j] += B[i][j];
    return C;
}
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& B)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix A is Empty");
    }
    if (B.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix B is Empty");
    }
    if ((*this) != B)
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix A != B");
    }
    return add(*this, B);
}
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& B)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix A is Empty");
    }
    if (B.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix B is Empty");
    }
    if (*this != B)
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsNotEqualException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix A != B");
    }
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->columns; ++j)
            (*this)[i][j] += B[i][j];
    return *this;
}

// Умножение матриц и матрицы на число
template<class T>
Matrix<T> mult(Matrix<T>& matrix, T element)
{
    if (matrix.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(matrix).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    for (size_t i = 0; i < matrix.GetRows(); ++i)
        for (size_t j = 0; j < matrix.GetColumns(); ++j)
            matrix[i][j] *= element;
    return matrix;
}
template <class T>
Matrix<T> Matrix<T>::operator*(T element)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    return mult(*this, element);
}
template <class T>
Matrix<T>& Matrix<T>::operator*=(T element)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    for (size_t i = 0; i < this->GetRows(); ++i)
        for (size_t j = 0; j < this->GetColumns(); ++j)
            (*this)[i][j] *= element;
    return *this;
}
template <class T>
Matrix<T> mult(Matrix<T>& A, Matrix<T>& B)
{
    if (A.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(A).name(), __LINE__ - 4, ctime(&t_time), "Matrix A is empty");
    }
    if (B.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(B).name(), __LINE__ - 4, ctime(&t_time), "Matrix B is empty");
    }
    if (A.GetColumns() != B.GetRows())
    {
        time_t t_time;
        t_time = time(NULL);
        throw CannotMultMatrixException(__FILE__, typeid(A).name(), __LINE__ - 4, ctime(&t_time),"You cannot mult these elements");
    }
    Matrix<T> C(A.GetRows(), B.GetColumns());
    for (size_t i = 0; i < C.GetRows(); ++i)
        for (size_t j = 0; j < C.GetColumns(); ++j)
        {
            C[i][j] = 0;
            for (size_t k = 0; k < A.GetColumns(); ++k)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}
template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& matrix)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix A is empty");
    }
    if (matrix.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix B is empty");
    }
    if (this->GetColumns() != matrix.GetRows())
    {
        time_t t_time;
        t_time = time(NULL);
        throw CannotMultMatrixException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "You cannot mult these elements");
    }
    return mult(*this, matrix);
}

// Транспонирование
template <class T>
Matrix<T> Matrix<T>::transpose(void)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    Matrix<T> res(this->GetColumns(), this->GetRows());
    for (size_t i = 0; i < res.GetRows(); ++i)
        for (size_t j = 0; j < res.GetColumns(); ++j)
            res[i][j] = (*this)[j][i];
    return res;
}
template <class T>
Matrix<T> Matrix<T>::operator!(void)
{
    if (this->IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    return this->transpose();
}

// Определитель
template <class T>
static Matrix<T> matrix_det(size_t count, size_t exclude_row, size_t exclude_column, const Matrix<T>& matrix)
{
    Matrix<T> new_matrix(count - 1, count - 1);
    size_t ki = 0, kj = 0;
    for (size_t i = 0; i < count - 1; ++i)
    {
        if (i == exclude_row)
            ki = 1;
        for (size_t j = 0; j < count - 1; ++j)
        {
            if (j == exclude_column)
                kj = 1;
            new_matrix[i][j] = matrix[i + ki][j + kj];
        }
    }
    return new_matrix;
}
template <class T>
static T determinant_value(const size_t count, const Matrix<T>& matrix)
{
    size_t sign = 1, new_count = count - 1;
    T det = 0;
    if (count == 1)
        return matrix[0][0];
    if (count == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    if (count > 2)
        for (size_t i = 0; i < count; ++i)
        {
            Matrix<T> new_matrix = matrix_det(count, i, 0, matrix);
            det = det + sign * matrix[i][0] * determinant_value(new_count, new_matrix);
            sign = -sign;
        }
    return det;
}
template <class T>
T Matrix<T>::determinant(void)
{
    if (!this->IsSquare())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsNotSquareException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "Matrix is not square");
    }
    T det = determinant_value(this->GetRows(), *this);
    return det;
}

// Проверка на пустату
template <class T>
bool Matrix<T>::IsEmpty(void) const
{
    if (this->GetRows() == 0 && this->GetColumns() == 0)
        return true;
    else
        return false;
}

// Проверка на квадратную матрицу
template <class T>
bool Matrix<T>::IsSquare(void) const
{
    if (this->GetRows() == this->GetColumns())
        return true;
    else
        return false;
}

#endif //OOP_LAB_02_MYMATH_H