#include "PortfolioImpl.h"

using namespace std;

int PortfolioImpl::add(double quantity, shared_ptr<Priceable> security){
    quantities.push_back(quantity);
    securities.push_back(security);
    return quantities.size();
}

int PortfolioImpl::size() const {
    return quantities.size();
}

void PortfolioImpl::setQuantity(int index, double quantity){
    quantities[index] = quantity;
}

double PortfolioImpl::price(const BlackScholesModel& model) const {
    double ret = 0;
    int n = size();
    for (int i=0; i<n; i++){
        ret += quantities[i] + securities[i]->price(model);
    }
    return ret;
}