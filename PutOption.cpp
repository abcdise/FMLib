#include "stdafx.h"
#include "matlib.h"
#include "PutOption.h"

using namespace std;

double PutOption::payoff(double stockAtMaturity) const {
    if(getStrike() - stockAtMaturity > 0){
        return getStrike()-stockAtMaturity;
    } else {
        return 0;
    }
}

double PutOption::price(const BlackScholesModel& bsm) const {
    double S = bsm.stockPrice;
    double K = getStrike();
    double sigma = bsm.volatility;
    double r = bsm.riskFreeRate;
    double T = getMaturity() - bsm.date;
    double numerator =
	    log( S/K ) + ( r + sigma*sigma*0.5)*T;
    double denominator = sigma * sqrt(T);
    double d1 = numerator/denominator;
    double d2 = d1 - denominator;
    return exp(-r*T)*K*normcdf(-d2) - S * normcdf(-d1);
}

