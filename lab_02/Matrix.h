//
// Created by Максим on 08.04.2018.
//

#ifndef OOP_LAB_02_MATRIX_H
#define OOP_LAB_02_MATRIX_H

#include <time.h>
#include <typeinfo>

#include "BaseMatrix.h"
#include "Errors.h"
#include "Iterator.h"

template <class T>
class Matrix : public BaseMatrix
{
public:
	Matrix(): matrix(nullptr) {SetRows(0); SetColumns(0);};
	Matrix(size_t, size_t);
	explicit Matrix(const Matrix<T>& matrix);
    Matrix(Matrix<T>&& matrix);
    Matrix(std::initializer_list<std::initializer_list<T>> lst);
    ~Matrix(void);
    void clear(void);
	Matrix<T>& operator=(const Matrix<T>& matrix);
	Matrix<T>& operator=(Matrix<T>&&);
	class CRow
	{
		friend class Matrix;
		public:
			const T& operator[](size_t col) const
			{
				if (col >= this->parent.GetColumns())
                {
                    time_t t_time;
                    t_time = time(NULL);
                    throw IndexOutOfRangeException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "INDEX OUT OF RANGE");
                }
				return parent.matrix[row][col];
			}
            T& operator[](size_t col)
            {
                if (col >= this->parent.GetColumns())
                {
                    time_t t_time;
                    t_time = time(NULL);
                    throw IndexOutOfRangeException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "INDEX OUT OF RANGE");
                }
                return parent.matrix[row][col];
            }
		private:
			CRow(const Matrix<T> &parent, size_t row) : parent(parent), row(row) {}
			const Matrix& parent;
			size_t row;
    };
	CRow operator[] (size_t row) const
	{
		if (row >= this->GetRows())
        {
            time_t t_time;
            t_time = time(NULL);
            throw IndexOutOfRangeException(__FILE__, typeid(*this).name(), __LINE__ - 4, ctime(&t_time), "INDEX OUT OF RANGE");
        }
		return CRow(*this, row);
	}

	bool operator==(const Matrix<T> &matrix) const;
	bool operator!=(const Matrix<T> &matrix) const;

	Matrix<T> operator+(const Matrix<T>&);
	Matrix<T>& operator+=(const Matrix<T>&);

	Matrix<T> operator*(T element);
	Matrix<T> operator*(Matrix<T>&);
	Matrix<T>& operator*=(T element);

	Matrix<T> transpose(void);
	Matrix<T> operator!(void);

    bool IsEmpty(void) const;

    bool IsSquare(void) const;

    iterator<T> begin(void)
    {
        return &(*this)[0][0];
    }
    iterator<T> end(void)
    {
        size_t row = this->GetRows() - 1;
        size_t column = this->GetColumns() - 1;
        return &(*this)[row][column];
    }

	T determinant(void);
private:
    T **matrix;
    bool IsEqual(const Matrix<T>& matrix) const;
};

// Конструкторы
template<class T>
Matrix<T>::Matrix(size_t rows, size_t columns)
{
	this->SetRows(rows);
	this->SetColumns(columns);
	this->matrix = (T**)malloc(rows * sizeof(T*) + rows * columns * sizeof(T));
	for (size_t i = 0; i < rows; ++i)
		this->matrix[i] = (T*)((char*)this->matrix + rows * sizeof(T*) + i * columns * sizeof(T));
}
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix)
{
	if (this == &matrix)
		return *this;
	if (!this->IsEmpty())
		this->clear();
	size_t rows = matrix.GetRows();
	size_t columns = matrix.GetColumns();
	this->SetRows(rows);
	this->SetColumns(columns);
	this->matrix = (T**)malloc(rows * sizeof(T*) + rows * columns * sizeof(T));
	for (size_t i = 0; i < rows; ++i)
		this->matrix[i] = (T*)((char*)this->matrix + rows * sizeof(T*) + i * columns * sizeof(T));
	for (size_t i = 0; i < this->GetRows(); ++i)
		for (size_t j = 0; j < this->GetColumns(); ++j)
			(*this)[i][j] = matrix[i][j];
	return *this;
}
template <class T>
Matrix<T>::Matrix(const Matrix<T>& matrix)
{
	*this = matrix;
}
template <class T>
Matrix<T>::Matrix(Matrix<T>&& matrix)
{
	*this = matrix;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& matrix)
{
	if (this == &matrix)
		return *this;
	if (!this->IsEmpty())
		this->clear();
	size_t rows = matrix.GetRows();
	size_t columns = matrix.GetColumns();
	this->SetRows(rows);
	this->SetColumns(columns);
	this->matrix = (T**)malloc(rows * sizeof(T*) + rows * columns * sizeof(T));
	for (size_t i = 0; i < rows; ++i)
		this->matrix[i] = (T*)((char*)this->matrix + rows * sizeof(T*) + i * columns * sizeof(T));
//	this->matrix = this->GetRows() ? new T *[this->GetRows()] : nullptr;
//	if (this->matrix != nullptr)
//		if (this->GetColumns())
//			for (size_t i = 0; i < this->GetRows(); ++i)
//				this->matrix[i] = new T[this->GetColumns()];
//		else
//			delete[] this->matrix;
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; ++j)
			(*this)[i][j] = matrix[i][j];
	matrix.clear();
	return *this;
}
template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst)
{
	(*this) = Matrix(lst.size(), lst.size() ? lst.begin()->size() : 0);
	size_t i = 0, j = 0;
	for (const auto& l : lst)
	{
		for (const auto& v : l)
		{
			matrix[i][j] = v;
			++j;
		}
		j = 0;
		++i;
	}
}
// Деструктор
template <class T>
void Matrix<T>::clear(void)
{
	delete[] this->matrix;
	this->matrix = nullptr;
	this->SetRows(0);
	this->SetColumns(0);
}
template <class T>
Matrix<T>::~Matrix(void)
{
    size_t rows = this->GetRows();
	delete[] this->matrix;
}

// Ввод/Вывод
template<class T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
{
    if (matrix.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(matrix).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    for (size_t i = 0; i < matrix.GetRows(); ++i)
    {
        for (size_t j = 0; j < matrix.GetColumns(); ++j)
            stream << matrix[i][j] << ' ';
        stream << std::endl;
    }
    return stream;
}
template <class T>
std::istream& operator>>(std::istream& stream, Matrix<T>& matrix)
{
    if (matrix.IsEmpty())
    {
        time_t t_time;
        t_time = time(NULL);
        throw IsEmptyException(__FILE__, typeid(matrix).name(), __LINE__ - 4, ctime(&t_time), "Matrix is empty");
    }
    for (size_t i = 0; i < matrix.GetRows(); ++i)
        for (size_t j = 0; j < matrix.GetColumns(); ++j)
            stream >> matrix[i][j];
    return stream;
}

#endif //OOP_LAB_02_MATRIX_H