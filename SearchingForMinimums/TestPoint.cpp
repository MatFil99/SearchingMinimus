
#include "TestPoint.h"
#include <iostream>


void TestPoint::testPoint() {
    double * tab = new double[115];
    for( int i=0; i<115; ++i ){ tab[i] = i; }
    VectorN v(115, tab);
    VectorN v2(v);

    VectorN v5(5);

    Point p(v, 10.10);

    Point p2(p);

    std::cout << p << p2;

    bool czyPrawda = p2==p;
    std::cout << czyPrawda;
}