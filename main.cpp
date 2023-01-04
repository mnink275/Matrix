#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix<int, 3, 3> mtx1(1);
    Matrix<int, 3, 3> mtx2(2);

    Matrix<int, 3, 3> mtx = mtx1 * mtx2;
    mtx.print();

    return 0;
}