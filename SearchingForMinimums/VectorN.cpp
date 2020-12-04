#include "VectorN.h"
#include <cmath>
#include <iostream>
#include <iomanip>

VectorN::VectorN(int n)
    :
    size(n)
{
    if(size > 0)
        vec = new double [n];
    else vec = nullptr;
    for (int i = 0; i < n ; ++i)
        vec[i] = 0;
}

VectorN::VectorN():
    size(-1)
{// pusty wektor
    vec = nullptr;
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
    if( vectN.getTab()!=nullptr ){
        vec = new double [vectN.getSize()];
        for(int i = 0; i < vectN.getSize(); i++){
            this->setNVal(i, vectN.getNVal(i));
        }
    }else{
        vec=nullptr;
        size=-1;
    }
}

VectorN::~VectorN() {
    if( vec!=nullptr ) delete [] vec;
}

double *VectorN::getTab() const {
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

VectorN& VectorN::operator=(const VectorN &v) {
    if(vec!=nullptr) delete[] vec;
    size = v.getSize();
    if( size < 0 ){
        size = -1;
        vec = nullptr;
        // pusty wektor, bo
    }else {
        vec = new double[size];
        for ( int i=0; i<size; ++i ){
            vec[i] = v.getNVal(i);
        }
    }
    return *this;
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

bool VectorN::isNull() const{
    return vec == nullptr;
}

std::ostream& operator<<(std::ostream& os, const VectorN& dt){
    if(dt.isNull()) return os << "Null VectorN";
    for( int i =0; i<dt.getSize(); i++){
        os << dt.getNVal(i) << ", ";
    }
    return os;
}