#include "stdafx.h"
#include "MonteCarloPricer.h"

using namespace std;

/* Constructor */
MonteCarloPricer::MonteCarloPricer(): nScenarios(10000) {
}

/* Public member function */
double MonteCarloPricer::price(const ContinuousTimeOption& o, const BlackScholesModel& bsm){
    return 0;
}