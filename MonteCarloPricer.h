#pragma once

#include "stdafx.h"
#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"

class MonteCarloPricer{
public:
    /* Constructor */
    MonteCarloPricer();

    /* Member attributes */
    int nScenarios;

    /* Member functions */
    double price(const ContinuousTimeOption& o, const BlackScholesModel& bsm);
};

/* Test */
void testMonteCarloPricer();