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
    auto degree = max(coefficients.size(), g.coefficients.size());
    vector<double> result_coef(degree, 0.0);
    for (auto i=0; i<coefficients.size(); i++){
        result_coef[i] += coefficients[i];
    }
    for (auto i=0; i<g.coefficients.size(); i++){
        result_coef[i] += g.coefficients[i];
    }
    coefficients = result_coef;
}

Polynomial operator+(Polynomial& f, const Polynomial& g){
    f.add(g);
    Polynomial h = f;
    return h;

}






static void testPolynomialFunctions(){
    vector<double> coef_x = {1.0, 2.0, 3.0};
    vector<double> coef_y = {1.0, 2.0, 3.0};
    vector<double> coef_z = {2.0, 4.0, 6.0};
    Polynomial f(coef_x);
    Polynomial g(coef_y);
    Polynomial h(coef_z);
    f = f + g;
    double final_result_1 = f(10.0);
    double final_result_2 = h(10.0);
    ASSERT(final_result_1 == final_result_2);
    ASSERT((final_result_1 - 642.0) == 0);
}

void testPolynomial(){
    TEST(testPolynomialFunctions);
}


