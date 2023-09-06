#pragma once

#include "Priceable.h"
#include "BlackScholesModel.h"

class ZeroCouponBond: public Priceable {
public:
    double price(BlackScholesModel& bsm) const;
    void setMaturity(double m){
        maturity = m;
    }
    double getMaturity() const {
        return maturity;
    }

private:
    double maturity;
};