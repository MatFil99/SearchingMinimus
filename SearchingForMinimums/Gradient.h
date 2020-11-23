#ifndef SEARCHINGFORMINIMUMS_GRADIENT_H
#define SEARCHINGFORMINIMUMS_GRADIENT_H

#include "VectorN.h"
#include "Function.h"

class Gradient {
    Function * function;
    int n;
public:
    Gradient(Function * f);
    VectorN get(VectorN point, double step);
};


#endif //SEARCHINGFORMINIMUMS_GRADIENT_H
