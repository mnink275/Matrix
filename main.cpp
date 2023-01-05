#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix<double, 2, 2> mtx;
    mtx[0][0] = 1;
    mtx[0][1] = 2;
    mtx[1][0] = 3;
    mtx[1][1] = 4;
    mtx.print();
    /*Matrix<double, 3, 3> mtx = mtx1 * mtx2;
    mtx.print();*/
    std::cout << mtx.det();

    return 0;
}