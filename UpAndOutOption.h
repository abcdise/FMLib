#pragma once

#include "KnockOutOption.h"

class UpAndOutOption: public KnockOutOption {
public:
    
    /* Override payoff function */

    bool barrierActivated(const std::vector<double>& path) const;

    double payoff(const std::vector<double>& p) const;
};


/* Unit testing */
void testUpAndOutOption();