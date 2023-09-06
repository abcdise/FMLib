#include "matlib.h"

class Matrix{
public:
    /* Constructor */
    Matrix(int nrows, int ncols, bool zeros=1);

    /* Destructor */
    ~Matrix(){
        delete[] data;
    }

    /* Methods */
    int nRows() const {
        return nrows;
    }
    int nCols() const {
        return ncols;
    }
    double get(int i, int j) const {
        return data[offset(i, j)];
    }
    void set (int i, int j, double value) {
        data[offset(i, j)] = value;
    }
    int offset(int i, int j) const {
        ASSERT(i>=0 && i<nrows && j>=0 && j<ncols);
        return j*nrows + i;
    }
    const double* begin() const {
        return data;
    }
    const double* end() const {
        return endPointer;
    }
    double* begin() {
        return data;
    }
    double* end() {
        return endPointer;
    }

private:
    int nrows;
    int ncols;
    double* data;
    double* endPointer;
};

/* Operator overloading */
Matrix operator+(const Matrix& x, const Matrix& y);
