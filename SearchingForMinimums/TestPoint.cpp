
#include "TestPoint.h"
#include <iostream>


void TestPoint::testujPunkt() {
    double * tab = new double[5];
    for( int i=0; i<5; ++i ){ tab[i] = i; }
    VectorN v(5, tab);
    VectorN v2(v);

    std::cout << v.getNVal(2);

    //Point p(v, 10.10);

    //VectorN v3(p.getVectorN());
    //std::cout <<v3.getNVal(2);

//    std::cout << p;


}