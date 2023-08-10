#pragma once

#include "stdafx.h"

class Polynomial{
public:
    /* Member variable*/
    std::vector<double> coefficients;

    /* Constructor */
    Polynomial();
    Polynomial(std::vector<double>& c);
    Polynomial(double c);

    /* Member definitions */
    double evaluate(double x) const;
    void add(const Polynomial& g);

    /* Overload () */
    double operator()(double x) const {
        return evaluate(x);
    };
};

Polynomial operator+(const Polynomial& f, const Polynomial g);
Polynomial operator-(const Polynomial& f, const Polynomial g);
Polynomial operator*(const Polynomial& f, const Polynomial g);
Polynomial operator+=(const Polynomial& f, const Polynomial g);


void testPolynomial();