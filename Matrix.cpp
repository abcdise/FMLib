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

/* Operator overloading within the class */
Matrix Matrix::operator-() const {
    Matrix ret(nrows, ncols, false);
    double* dest = ret.begin();
    const double* start = data;
    const double* end = endPointer;
    while (start!=end){
        *(dest++) = -*(start++);
    }
    return ret;
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

Matrix operator+ (const Matrix& x, double y){
    Matrix ret(x.nRows(), x.nCols(), false);
    double* dest = ret.begin();
    const double* start = x.begin();
    const double* end = x.end();
    while (start!=end){
        *(dest++) = *(start++) + y;
    }
    return ret;
}

Matrix operator + (double x, const Matrix& y){
    return y + x;
}

Matrix operator - (const Matrix& x, const Matrix& y){
    return x + (-y);
}

Matrix operator - (const Matrix& x, double y){
    return x + (-y);
}

Matrix operator - (double x, const Matrix& y){
    return x + (-y);
}

Matrix operator * (const Matrix& x, const Matrix& y){
    ASSERT(x.nCols()==x.nRows());
    Matrix ret(x.nRows(), y.nCols(), false);
    for (int i=0; i<ret.nRows(); i++){
        for (int j=0; j<ret.nCols(); j++){
            double summand = 0;
            for (int k=0; k<x.nCols(); k++){
                summand += x(i, k) * y(k, j);
            }
            ret.set(i, j, summand);
        }
    }
    return ret;
}

Matrix operator * (const Matrix& x, double y){
    Matrix ret(x.nRows(),x.nCols(), false);
    double* dest = ret.begin();
    const double* start = x.begin();
    const double* end = x.end();
    while (start!=end){
        *(dest++) = *(start++) * y;
    }
    return ret;
}

Matrix operator * (double x, const Matrix& y){
    return y * x;
}