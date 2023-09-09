#include "stdafx.h"
#include "matlib.h"
#include "Portfolio.h"
#include "CallOption.h"
#include "BlackScholesModel.h"
#include "Polynomial.h"
#include "UpAndOutOption.h"
#include "Matrix.h"
#include "Playground.h"


using namespace std;

int main() {
    testMatlib();
    testCallOption();
    testBlackScholesModel();
    testPolynomial();
    testUpAndOutOption();
    testPlayground();
    testPortfolio();
    testMatrix();
}