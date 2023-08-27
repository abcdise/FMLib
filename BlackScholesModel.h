#pragma once

#include "stdafx.h"

class BlackScholesModel {
public:
    /* Member attributes */
    double drift;
    double stockPrice; // current price
    double volatility;
    double riskFreeRate;
    double date; // current date

    /* Constructor */
    BlackScholesModel();

    /* Member functions */

    std::vector<double> generatePricePath(double toDate, int nSteps) const;
    std::vector<double> generateRiskNeutralPricePath(double toDate, int nSteps) const;

private:
    /* Member functions */
    std::vector<double> generateRiskNeutralPricePath(double toDate, int nSteps, double drift) const;
};



void testBlackScholesModel();