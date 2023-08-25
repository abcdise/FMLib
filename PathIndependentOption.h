#include "stdafx.h"
#include "ContinuousTimeOptionBase.h"

class PathIndependentOption: public ContinuousTimeOptionBase{
public:

    /* Methods */
    virtual double payoff(double endStockPrice) const = 0;
    
    double payoff(const std::vector<double>& stockPrices) const {
        return payoff(stockPrices.back());
    };
    bool isPathDependent(){
        return false;
    }

    /* Virtual destructor */
    virtual ~PathIndependentOption(){};
};