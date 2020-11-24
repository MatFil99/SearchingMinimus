#ifndef SEARCHINGFORMINIMUMS_FUNCTION_H
#define SEARCHINGFORMINIMUMS_FUNCTION_H


#include "fparser4.5.2/fparser.hh"
#include "VectorN.h"

class Gradient;

class Function {
    int varNum;
    FunctionParser parser;
    Gradient * gradient;

public:
    Function(std::string & f );

    double getValue(VectorN);
    int getVarNum();
    VectorN getGradient(VectorN);

};


#endif //SEARCHINGFORMINIMUMS_FUNCTION_H
