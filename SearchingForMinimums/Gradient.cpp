#include "Gradient.h"

Gradient::Gradient(Function * f) {
    function = f;
    n = function->getVarNum();
}

VectorN Gradient::get(VectorN point, double step) {
    VectorN gradient(n);
    double val;
    for (int i = 0; i < n; ++i){
        VectorN start(point), end(point);
        start.setNVal(i, point.getNVal(i) - step);
        end.setNVal(i, point.getNVal(i) + step);
        val = (function->getValue(end) - function->getValue(start))/(2*step);
        gradient.setNVal(i, val);
    }
    function->getValue(point);
    return gradient;
}
