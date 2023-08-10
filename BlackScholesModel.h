#pragma once

#include "stdafx.h"

class BlackScholesModel {
public:
    /* Member variables */
    double stockPrice;
    double volatility;
    double riskFreeRate;
    double date;

    /* Constructor */
    BlackScholesModel();
};



void testBlackScholesModel();