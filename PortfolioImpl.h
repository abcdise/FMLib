#pragma once

#include "Priceable.h"
#include "Portfolio.h"
#include "BlackScholesModel.h"

class PortfolioImpl: public Portfolio {
public:
    int size() const;
    int add(double quantity, std::shared_ptr<Priceable> security);
    void setQuantity(int index, double quantity);
    double price(const BlackScholesModel& model) const;
    std::vector<double> quantities;
    std::vector<std::shared_ptr<Priceable>> securities;
};