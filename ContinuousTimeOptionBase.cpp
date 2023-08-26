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


/* Test */



