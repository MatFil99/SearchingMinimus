#include "VectorN.h"
#include <cmath>

VectorN::VectorN(int n) {
    vec = new double [n];
    for (int i = 0; i < n ; ++i)
        vec[n] = 0;
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

int VectorN::getSize() {
    return size;
}

double VectorN::getNorm() {
    double norm = 0;
    for (int i = 0; i < size; ++i){
        norm += vec[i]*vec[i];
    }
    norm = pow(norm, 0.5);
    return norm;
}
