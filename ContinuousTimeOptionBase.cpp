#include "stdafx.h"
#include "ContinuousTimeOptionBase.h"
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "CallOption.h"

using namespace std;

double ContinuousTimeOptionBase::price(const BlackScholesModel& bsm) const {
    MonteCarloPricer pricer;
    return pricer.price(*this, bsm);
}

double ContinuousTimeOptionBase::delta(double stockPrice, BlackScholesModel& bsm) const {
    double h = stockPrice * pow(10.0, -6);
    bsm.stockPrice = stockPrice + h;
    double price_1 = price(bsm);
    bsm.stockPrice = stockPrice - h;
    double price_2 = price(bsm);
    return (price_1 - price_2) / (2 * h);
}


/* Test */



