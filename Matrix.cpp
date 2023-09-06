#include "Matrix.h"

/* Constructor */
Matrix::Matrix(int nrows, int ncols, bool zeros): nrows(nrows), ncols(ncols) {
    int size = nrows * ncols;
    data = new double[size];
    endPointer = data + size;
    if (zeros){
        memset(data, 0.0, sizeof(double)*size);
    }
}

/* Operator overloading */
Matrix operator+ (const Matrix& x, const Matrix& y){
    ASSERT(x.nRows()==y.nRows() && x.nCols()==y.nCols());
    Matrix ret(x.nRows(), x.nCols(), false);
    double* dest = ret.begin();
    const double* s1 = x.begin();
    const double* s2 = y.begin();
    const double* end = x.end();
    while (s1!=end){
        *(dest++) = *(s1++) + *(s2++);
    }
    return ret;
}