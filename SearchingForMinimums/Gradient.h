#ifndef SEARCHINGFORMINIMUMS_GRADIENT_H
#define SEARCHINGFORMINIMUMS_GRADIENT_H

#include "VectorN.h"
#include <float.h>


class Function;

class Gradient {
    Function * function;
    int n;

public:
    Gradient(Function * f);
    VectorN get(VectorN point, double step = Gradient::PRECISION_GRADIENT);
    
    constexpr static const double PRECISION_GRADIENT = 0.000005;
};


#endif //SEARCHINGFORMINIMUMS_GRADIENT_H
