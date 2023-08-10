#include "Polynomial.h"
#include "stdafx.h"
#include "testing.h"
using namespace std;


    // /* Constructor */
    // Polynomial();
    // Polynomial(std::vector<double>& c);
    // Polynomial(double c);

    // /* Member definitions */
    // double evaluate(double x);
    // Polynomial add(Polynomial& g);

Polynomial::Polynomial(){
    vector<double> c = {0.0};
    coefficients = c;
}

Polynomial::Polynomial(vector<double>& c){
    coefficients = c;
}

Polynomial::Polynomial(double c){
    vector<double> v = {c};
    coefficients = v;
}

double Polynomial::evaluate(double x) const {
    double sum = 0;
    for (auto i=0; i<coefficients.size(); i++){
        sum += coefficients[i] * pow(x, i);
    }
    return sum;
}

void Polynomial::add(const Polynomial& g){
    vector<double> y = g.coefficients;
    for (auto i=0; i<coefficients.size(); i++){
        coefficients[i] += y[i];
    }
}

static void testPolynomialFunctions(){
    vector<double> coef_x = {1.0, 2.0, 3.0};
    vector<double> coef_y = {1.0, 2.0, 3.0};
    vector<double> coef_z = {2.0, 4.0, 6.0};
    Polynomial f(coef_x);
    Polynomial g(coef_y);
    Polynomial h(coef_z);
    f.add(g);
    double final_result_1 = f.evaluate(10.0);
    double final_result_2 = h.evaluate(10.0);
    ASSERT(final_result_1 == final_result_2);
    ASSERT((final_result_1 - 642.0) == 0);
}

void testPolynomial(){
    TEST(testPolynomialFunctions);
}


