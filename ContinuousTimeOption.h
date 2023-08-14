#pragma once
#include "stdafx.h"

class ContinuousTimeOption{
public:
    /* virtual destructor */
    virtual ~ContinuousTimeOption(){};

    /* Maturity */
    virtual double getMaturity() const = 0;

    /* Payoff function */
    virtual double payoff(std::vector<double>& stockPrices) const = 0;

    /* Is the option path-dependent? */
    virtual bool isPathDependent() const = 0;
};