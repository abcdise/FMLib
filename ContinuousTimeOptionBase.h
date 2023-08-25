#pragma once
#include "stdafx.h"
#include "ContinuousTimeOption.h"
#include "BlackScholesModel.h"


/* Specify the maturity, strike, and the pricing method */
class ContinuousTimeOptionBase: public ContinuousTimeOption{
public:
    virtual ~ContinuousTimeOptionBase() {}
    double getMaturity() const {
        return maturity;
    }
    void setMaturity(double m) {
        this->maturity = m;
    }
    double getStrike() const {
        return strike;
    }
    void setStrike(double s) {
        this->strike = s;
    }

    /* Price the option using Black Scholes Model */
    double price(const BlackScholesModel& bsm) const;
private:
    double maturity;
    double strike;
};