#pragma once
#include "Priceable.h"
#include "stdafx.h"

class ContinuousTimeOption: public Priceable {
public:
    /* virtual destructor */
    virtual ~ContinuousTimeOption(){};

    /* Maturity */
    virtual double getMaturity() const = 0;

    /* Payoff function */
    virtual double payoff(const std::vector<double>& stockPrices) const = 0;

    /* Is the option path-dependent? */
    virtual bool isPathDependent() const = 0;
};