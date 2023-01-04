#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix<int, 2, 3> mtx1(1);
    Matrix<int, 3, 2> mtx2(2.2);

    Matrix<int, 2, 2> mtx = mtx1 * mtx2;
    mtx.print();

    return 0;
}