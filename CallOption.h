#pragma once

#include "stdafx.h"
#include "BlackScholesModel.h"

class CallOption {
public:
    /* Members */
    double strike;
    double maturity;

    /* Constructor*/
    CallOption();
    CallOption(double s, double m);

    double payoff( double stockAtMaturity ) const;

    double price( const BlackScholesModel& bsm )
        const;
};



void testCallOption();