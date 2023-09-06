#include "ZeroCouponBond.h"
#include "stdafx.h"

double ZeroCouponBond::price(BlackScholesModel& bsm) const {
    double T = getMaturity() - bsm.date;
    double r = bsm.riskFreeRate;
    return exp(-r * T);
}