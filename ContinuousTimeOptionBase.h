#pragma once
#include "stdafx.h"
#include "ContinuousTimeOption.h"

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
    double price(const BlackScholesModel& bsm) const{}
private:
    double maturity;
    double strike;
};