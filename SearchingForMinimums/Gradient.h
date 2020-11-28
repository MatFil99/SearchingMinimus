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
    VectorN get(VectorN point, double step = DBL_MIN);
};


#endif //SEARCHINGFORMINIMUMS_GRADIENT_H
