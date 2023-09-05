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
 

int PortfolioImpl::size() const {
    return quantities.size();
}
 
int PortfolioImpl::add( double quantity,
            shared_ptr<Priceable> security ) {
    quantities.push_back( quantity );
    securities.push_back( security );
    return quantities.size();
}
 
double PortfolioImpl::price(
        const BlackScholesModel& model ) const {
    double ret = 0;
    int n = size();
    for (int i=0; i<n; i++) {
        ret += quantities[i]
               * securities[i]->price( model );
    }
    return ret;
}
void PortfolioImpl::setQuantity( int index,
        double quantity ) {
    quantities[index] = quantity;
}

shared_ptr<Portfolio> Portfolio::newInstance() {
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>();
    return ret;
}