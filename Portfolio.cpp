#include "Portfolio.h"
#include "PortfolioImpl.h"

using namespace std;

shared_ptr<Portfolio> Portfolio::newInstance(){
    shared_ptr<Portfolio> ret = make_shared<PortfolioImpl>();
    return ret;
}