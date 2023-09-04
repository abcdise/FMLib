#pragma once

#include "Priceable.h"

class Portfolio: public Priceable {
public:
    /* Virtual destructor */
    virtual ~Portfolio(){};
    /* Number of items in the portfolio */
    virtual int size() const = 0;
    /* 
    Add a new security to the portfolio and return the index at which 
    it is added
    */
    virtual int add(double quantity, std::shared_ptr<Priceable> security) = 0;
    /* Set the quantity of a certain security */
    virtual void setQuantity(int index, double quantity) = 0;
    /* Compute the current price */
    virtual double price(const BlackScholesModel& model) = 0;
    /* Create a portfolio */
    static std::shared_ptr<Portfolio> newInstance();

};