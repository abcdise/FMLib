#pragma once

#include "ContinuousTimeOptionBase.h"

class PathDependentOption: public ContinuousTimeOptionBase{
public:
/* virtual destructor */
~PathDependentOption(){};

/* Methods */
bool isPathDependent() const {
    return true;
};
};