#include "stdafx.h"
#include "matlib.h"
#include "MonteCarloPricer.h"
#include "CallOption.h"

using namespace std;

/* Constructor */
MonteCarloPricer::MonteCarloPricer(): nScenarios(10000) {
}

/* Public member function */

/* 
    Price a continuous time option assuming the underlying stock prices follow 
    the Black Scholes Model
*/

double MonteCarloPricer::price(const ContinuousTimeOption& o, const BlackScholesModel& model){
    rng("default");
    double total = 0.0;
    for (int i=0; i<nScenarios; i++){
        vector<double> path=model.generateRiskNeutralPricePath(o.getMaturity(), 1);
        double payoff = o.payoff(path);
        total += payoff;
    }
    double mean = total / nScenarios;
    double r = model.riskFreeRate;
    double T = o.getMaturity() - model.date;
    return exp(-r * T) * mean;
    return 0;
}


/*
    Unit Testing
*/

static void testPriceCallOption(){
    rng("default");

    CallOption c;
    c.setStrike(110.0);
    c.setMaturity(2);

    BlackScholesModel m;
    m.volatility = 0.1;
    m.riskFreeRate = 0.05;
    m.stockPrice = 100.0;
    m.drift = 0.1;
    m.date = 1;

    MonteCarloPricer pricer;
    double price = pricer.price(c, m);
    double expected = c.price(m);
    ASSERT_APPROX_EQUAL(price, expected, 0.1);

}