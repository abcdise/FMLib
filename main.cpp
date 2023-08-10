#include "matlib.h"
#include "CallOption.h"
#include "BlackScholesModel.h"
#include "Polynomial.h"

using namespace std;

int main() {
    testMatlib();
    testCallOption();
    testBlackScholesModel();
    // testPolynomial();
    vector<double> x = {0.0, 0.0};
}