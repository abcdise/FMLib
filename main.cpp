#include "stdafx.h"
#include "matlib.h"
#include "CallOption.h"
#include "BlackScholesModel.h"
#include "Polynomial.h"
#include "UpAndOutOption.h"


using namespace std;

int main() {
    testMatlib();
    testCallOption();
    testBlackScholesModel();
    testPolynomial();
    testUpAndOutOption();
}