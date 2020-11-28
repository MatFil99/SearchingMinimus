#ifndef SEARCHINGFORMINIMUMS_POINT_H
#define SEARCHINGFORMINIMUMS_POINT_H


#include "VectorN.h"
#include <iostream>

class Point {
    VectorN * point;
    double value;

    Point& operator=(const Point & pPoint);

public:
    Point( Point const &pPoint);
    Point();
    Point(VectorN vectorN, double val);
    ~Point();
    double getValue()const;
    VectorN getVectorN()const;

    bool operator==(const Point & point);
};

std::ostream& operator<<(std::ostream& os, const Point& dt);


#endif //SEARCHINGFORMINIMUMS_POINT_H
