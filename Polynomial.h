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
};


void testPolynomial();