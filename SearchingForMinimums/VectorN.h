#ifndef SEARCHINGFORMINIMUMS_VECTORN_H
#define SEARCHINGFORMINIMUMS_VECTORN_H

// #define  0.05

#include <iostream>

class VectorN {
private:
    double * vec;
    int size;


public:

    VectorN();
    VectorN(int n);
    VectorN(int n, double vec[]);
    VectorN( const VectorN & vectN );
    ~VectorN();

    double * getTab()const;

    void setNVal(int n, double val);

    double getNVal(int n) const;

    int getSize() const;

    double getNorm();

    const double ACCEPTABLEDEVIATION = 0.05;

    bool operator ==( const VectorN & v ) const;
    bool operator !=( const VectorN & v ) const;

    VectorN operator +( const VectorN & v ) const;
    VectorN operator -( const VectorN & v ) const;
    VectorN multiply (double scalar) const;
    VectorN& operator =( const VectorN & v );

    bool roundEquals(const VectorN & v, int n, double acceptableDeviation) const;

    bool isNull() const;
};

std::ostream& operator<<(std::ostream& os, const VectorN& dt);

#endif //SEARCHINGFORMINIMUMS_VECTORN_H
