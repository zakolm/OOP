#include <iostream>

#include "MyMath.h"

int main(void)
{
    try
    {
        size_t rows = 0, columns = 0;
        std::cout << "Input rows: ";
        std::cin >> rows;
        std::cout << "Input columns: ";
        std::cin >> columns;

        Matrix<int> a = {{1,2,3}, {4,5,6}};//(rows, columns);
//      Matrix<int> a(rows, columns);
        Matrix<double> b(rows, columns);
        std::cin >> b;

//      for (size_t i = 0; i < a.GetRows(); ++i)
//          for (size_t j = 0; j < a.GetColumns(); ++j)
//              a[i][j] = i + j;
//      std::cout << "Your matrix A[" << a.GetRows() << "][" << a.GetColumns() << "]:" << std::endl << a;
//      Matrix<int> b = a;
        std::cout << "Your matrix B[" << b.GetRows() << "][" << b.GetColumns() << "]:" << std::endl << b;
//      b = transp(b);
        std::cout << "Transp matrix B[" << b.GetRows() << "][" << b.GetColumns() << "]:" << std::endl << !b;
//      Matrix<int> c(rows, columns);
//      c = a + b;
//      c = b;
//      std::cout << "Yor matrix C[" << a.GetRows() << "][" << a.GetColumns() << "]:" << std::endl << c;
//        std::cout << "Determinant matrix B: " << b.determinant() << std::endl;
//        double* it = b.end();
//        std::cout << "First element: " << *it << " Second element: " << *(it-1) << std::endl;
        iterator<int> it = a.begin();
        iterator<int> end = a.end();
        std::cout << std::endl << "Iterator: Matrix A[" << a.GetRows() << "][" << a.GetColumns() << "]:" << std::endl;
        for (; it < end; ++it)
            std::cout << *it << " ";
    }
    catch (base_exception& e)
    {
       std::cout << e.what();
    }
    return 0;
}