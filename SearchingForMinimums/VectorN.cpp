#include "VectorN.h"
#include <cmath>
#include <iostream>

VectorN::VectorN(int n)
    :
    size(n),
    vec(new double [n])
{
    vec = new double [n];
    size = n;
    for (int i = 0; i < n ; ++i)
        vec[i] = 0;
}

VectorN::VectorN(int n, double vect[]){
    vec = new double [n];
    this->size = n;
    for( int i = 0; i<n; ++i ){
        this->setNVal(i, vect[i]);
    }
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

bool VectorN::operator==(const VectorN &v) const {
    for(int i=0; i<v.getSize(); i++){
        if(!this->roundEquals(v, i, ACCEPTABLEDEVIATION)){// accaptabledeviation could adopt, but now it is constant
            return false;
        }
    }
    return true;
}

bool VectorN::roundEquals(const VectorN & v, int n, double acceptableDeviation) const {
    return std::abs(this->getNVal(n) - v.getNVal(n)) < acceptableDeviation; // check if it throw exception?
}

VectorN VectorN::operator+(const VectorN &v) const {
    VectorN result(*this);
    for (int i = 0; i < size; ++i){
        result.setNVal(i, vec[i] + v.getNVal(i));
    }
    return result;
}

VectorN VectorN::operator-(const VectorN &v) const {
    VectorN result(*this);
    for (int i = 0; i < size; ++i){
        result.setNVal(i, vec[i] - v.getNVal(i));
    }
    return result;
}

VectorN VectorN::multiply(const double scalar) const {
    VectorN result(*this);
    for (int i = 0; i < size; ++i){
        result.setNVal(i, scalar * vec[i] );
    }
    return result;
}

bool VectorN::operator!=(const VectorN &v) const {
    return !(*this == v);
}

std::ostream& operator<<(std::ostream& os, const VectorN& dt){
    for( int i =0; i<dt.getSize(); i++){
        os << dt.getNVal(i) << ", ";
    }
    return os;
}