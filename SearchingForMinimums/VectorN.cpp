#include "VectorN.h"
#include <cmath>

VectorN::VectorN(int n) {
    vec = new double [n];
    for (int i = 0; i < n ; ++i)
        vec[n] = 0;
}

VectorN::VectorN(int n, double * vect) {
    this->size = n;
    this->vec = vect;
}

VectorN::VectorN( const VectorN & vectN ){
    size = vectN.getSize();
    vec = new double [vectN.getSize()];
    for(int i = 0; i < vectN.getSize(); i++){
        this->setNVal(i, vectN.getNVal(i));
    }
}

VectorN::~VectorN() {
    delete [] vec;
}

double *VectorN::getTab() {
    return vec;
}

double VectorN::getNVal(int n) const {
    return vec[n];
}

void VectorN::setNVal(int n, double val) {
    vec[n] = val;
}

int VectorN::getSize() const{
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

bool VectorN::operator==(const VectorN &v) {
    bool ifEquals = true;
    for(int i=0; i<v.getSize(); i++){
        if(this->roundEquals(v, i, ACCEPTABLEDEVIATION)){// accaptabledeviation could adopt, but now it is constant
            ifEquals = false;
            break;
        }
    }
}

bool VectorN::roundEquals(const VectorN & v, int n, double acceptableDeviation) const {
    return abs(this->getNVal(n) - v.getNVal(n)) < acceptableDeviation; // check if it throw exception?
}