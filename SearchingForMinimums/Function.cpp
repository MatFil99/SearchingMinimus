#include "Function.h"


Function::Function(std::string &f) {
    parser.ParseAndDeduceVariables(f, &varNum);
}

double Function::getValue(VectorN point) {
    //sprawdzic czy punkt tego samego wymiaru co funkcja
    return parser.Eval(point.getTab());
}

int Function::getVarNum() {
    return varNum;
}

VectorN Function::getGradient(VectorN point) {
    //sprawdzic czy punkt tego samego wymiaru co funkcja
//    return gradient.get();
}
