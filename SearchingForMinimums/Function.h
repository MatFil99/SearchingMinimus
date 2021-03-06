#ifndef SEARCHINGFORMINIMUMS_FUNCTION_H
#define SEARCHINGFORMINIMUMS_FUNCTION_H


#include "fparser4.5.2/fparser.hh"
#include "VectorN.h"
#include <float.h>

class Gradient;

class Function {
    int varNum;
    FunctionParser parser;
    Gradient * gradient;

    constexpr static const double STEP_GRADIENT=0.00005;

public:
    Function(std::string &f);
    Function(std::string &f, int dimVec);
    Function(){;}

    ~Function();

    double getValue(VectorN);
    int getVarNum();
    VectorN getGradient(VectorN, double step = Function::STEP_GRADIENT);

};


#endif //SEARCHINGFORMINIMUMS_FUNCTION_H
