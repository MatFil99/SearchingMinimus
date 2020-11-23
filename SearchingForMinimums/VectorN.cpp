#include "VectorN.h"

VectorN::VectorN(int n) {
    vec = new double [n];
}

VectorN::~VectorN() {
    delete [] vec;
}

double *VectorN::getTab() {
    return vec;
}

double VectorN::getNVal(int n) {
    return vec[n];
}

void VectorN::setNVal(int n, double val) {
    vec[n] = val;
}