#include "Matrix.h"
#include "testing.h"


using namespace std;

/* Constructor */
Matrix::Matrix( string s ) {
    char separator;
    // read once to compute the size
    nrows = 1;
    ncols = 1;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (s[i]==';') {
            nrows++;
        }
        if (nrows==1 && s[i]==',') {
            ncols++;
        }
    }
 
    // now check we can read the string
    stringstream ss1;
    ss1.str(s);
    for (int i=0; i<nrows; i++) {
        for (int j=0; j<ncols; j++) {
            double ignored;
            ss1 >> ignored;
            ss1 >> separator;
            if (j==ncols-1 && i<nrows-1) {
                ASSERT( separator==';' );
            } else if (j<ncols-1) {
                ASSERT( separator==',' );
            }
        }
    }
 
    // allocate memory now we know nothing will go wrong
    stringstream ss;
    ss.str(s);
    int size = nrows*ncols;
    data = new double[size];
    endPointer = data+size;
    for (int i=0; i<nrows; i++) {
        for (int j=0; j<ncols; j++) {
            double* p = begin() + offset( i,j );
            ss >> (*p);
            ss >> separator;
        }
    }
}

Matrix::Matrix(int nrows, int ncols, bool zeros): nrows(nrows), ncols(ncols) {
    int size = nrows * ncols;
    data = new double[size];
    endPointer = data + size;
    if (zeros){
        memset(data, 0.0, sizeof(double)*size);
    }
}

/* Methods */

void Matrix::assign(const Matrix& other){
        nrows = other.nRows();
        ncols = other.nCols();
        int size = nrows * ncols;
        data = new double[size];
        endPointer = data + size;
        memcpy(data, other.data, sizeof(double)*size);
    }

Matrix Matrix::choleskyDecomposition(){
    ASSERT(ncols == nrows);
    Matrix ret(nrows, ncols, true);
    double* dest = ret.data;
    for (int i=0; i<ncols; i++){
        for (int j=0; i<nrows; j++){
            double summand = 0;
            if (i == j){
                for (int k=0; k<j; k++){
                    summand += pow(ret(j, k), 2);
                }
                ret(i, j) = sqrt(get(i, j) - summand); 
            } else if (i < j){
                for (int k=0; k<j; k++){
                    summand += ret(i, k) * ret(j, k);
                }
                ret(i, j) = 1 / ret(j, j) * (get(i, j) - summand);
            }
        }
    }
    return ret;
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

bool operator == (const Matrix& x, const Matrix& y){
    if (x.nCols() != y.nCols() | x.nRows() != y.nRows()){
        return false;
    } else {
        for (int i=0; i<x.nRows(); i++){
            for (int j=0; j<x.nCols(); j++){
                if (x(i, j) != y(i, j)){
                    return false;
                }
            }
        }
    }
    return true;
}




/* ===== Unit Testing ===== */
static void testMatrixConstructor(){
    Matrix X("1, 0, 0; 0, 1, 0; 0, 0, 1");
    ASSERT(X.nCols() == 3);
    ASSERT(X.nRows() == 3);
    ASSERT(X+X==2*X);
}

void testMatrix(){
    TEST(testMatrixConstructor);
}

