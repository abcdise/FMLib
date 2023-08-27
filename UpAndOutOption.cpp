#include "stdafx.h"
#include "UpAndOutOption.h"
#include <vector>
#include "testing.h"

using namespace std;

bool UpAndOutOption::barrierActivated(const vector<double>& path) const {
    bool check = false;
    for (double price: path){
        if (price >= getBarrier()){
            check = true;
            break;
        }
    }
    return check;
}

double UpAndOutOption::payoff(const vector<double>& path) const {
    if (barrierActivated(path)){
        return 0;
    } else {
        if ((path.back()-getStrike())>0){
            return path.back()-getStrike();
        } else {
            return 0;
        }
    }
    return 0;
}




/* Unit testing */
static void testKnockout(){
    vector<double> path({0.0, 1.0, 2.0, 3.0, 4.0});
    UpAndOutOption o;
    o.setBarrier(5.0);
    ASSERT_APPROX_EQUAL(o.barrierActivated(path), 0.0, 0.0);
}

void testUpAndOutOption(){
    TEST(testKnockout);
}