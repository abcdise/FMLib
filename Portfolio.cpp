#include "Portfolio.h"
using namespace std;

/* Implication class */
class PortfolioImpl: public Portfolio {
public:
    int size() const;
    int add(double quantity, shared_ptr<Priceable> security);
    void setQuantity(int index, double quantity);
    double price(const BlackScholesModel& model) const;
    vector<double> quantities;
    vector<shared_ptr<Priceable>> securities;
};

shared_ptr<Portfolio> Portfolio::newInstance(){
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>();
    return ret;
}

int PortfolioImpl::size() const {
    return int(securities.size());
}

int PortfolioImpl::add(double quantity, shared_ptr<Priceable> security) {
    securities.push_back(security);
    quantities.push_back(quantity);
    return int(securities.size());
}

void PortfolioImpl::setQuantity(int index, double quantity) {
    quantities[index] = quantity;
}

double PortfolioImpl::price(const BlackScholesModel& model) const {
    double ret = 0;
    auto n = size();
    for (auto i=0; i<n; i++){
        ret += quantities[i] * securities[i]->price(model);
    }
    return ret;
}