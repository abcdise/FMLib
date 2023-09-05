#pragma once

#include "PathIndependentOption.h"
#include "BlackScholesModel.h"

class PutOption: public PathIndependentOption {
public:
    double payoff(double stockAtMaturity) const;
    double price (const BlackScholesModel& bsm) const;
};