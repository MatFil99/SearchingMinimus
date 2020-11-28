#ifndef SEARCHINGFORMINIMUMS_POINT_H
#define SEARCHINGFORMINIMUMS_POINT_H


#include "VectorN.h"
#include <iostream>
#include "float.h"



class Point {
    VectorN * point;
    double value;

public:
    Point( Point const &pPoint);
    Point();
    Point(VectorN vectorN, double val);
    ~Point();
    double getValue()const;
    VectorN getVectorN()const;
    Point& operator=(const Point & pPoint);
    bool operator==(const Point & point);
    bool isNull();
};

std::ostream& operator<<(std::ostream& os, const Point& dt);


#endif //SEARCHINGFORMINIMUMS_POINT_H
