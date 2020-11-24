#include "Function.h"

#include "Gradient.h"


Function::Function(std::string &f) {
    parser.ParseAndDeduceVariables(f, &varNum);
    gradient = new Gradient(this);
}


double Function::getValue(VectorN point) {
    //sprawdzic czy punkt tego samego wymiaru co funkcja
    return parser.Eval(point.getTab());
}

int Function::getVarNum() {
    return varNum;
}

VectorN Function::getGradient(VectorN point, double step) {
    //sprawdzic czy punkt tego samego wymiaru co funkcja
    return gradient ->get(point, step);
}

Function::~Function() {
    delete gradient;
}
