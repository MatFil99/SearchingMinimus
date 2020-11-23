#ifndef SEARCHINGFORMINIMUMS_POINT_H
#define SEARCHINGFORMINIMUMS_POINT_H


#include "VectorN.h"
#include <iostream>

class Point {
    Point(VectorN vectorN, double val);

    VectorN * point;
    double value;
    bool operator==(const Point & point);

    Point& operator=(const Point & pPoint);

public:
    Point( Point *pPoint);
    Point();
    Point(VectorN &vectorN, double val);

    double getValue()const;
    VectorN getVectorN()const;
};

std::ostream& operator<<(std::ostream& os, const Point& dt);


#endif //SEARCHINGFORMINIMUMS_POINT_H
