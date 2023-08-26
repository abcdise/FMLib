#pragma once
#include <vector>
#include "PathDependentOption.h"

class KnockOutOption: public PathDependentOption {
public:
    /* Virtual destructor */
    virtual ~KnockOutOption(){};

    /* Interaction with private members */
    double getBarrier() const {
        return barrier;
    }
    void setBarrier(double b) {
        barrier = b;
    }

    /* Check if the barrier is activated */
    virtual bool barrierActivated(const std::vector<double>& path) const = 0;


private:
    double barrier;
};