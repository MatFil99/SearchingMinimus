#ifndef SEARCHINGFORMINIMUMS_GRADIENT_H
#define SEARCHINGFORMINIMUMS_GRADIENT_H

#include "fparser4.5.2/fparser.hh"

class Gradient {
    Gradient(FunctionParser parser);
    FunctionParser parser;
    double * gradient(double * point);
    double * gradientNorm(double * point);
};


#endif //SEARCHINGFORMINIMUMS_GRADIENT_H
