#ifndef SEARCHINGFORMINIMUMS_POINT_H
#define SEARCHINGFORMINIMUMS_POINT_H


#include "VectorN.h"
#include <iostream>
#include "float.h"



class Point {
    public:
    VectorN * point;
    double value;


    Point( Point const &pPoint);
    Point();
    Point(VectorN vectorN, double val);
    ~Point();
    double getValue()const;
    VectorN getVectorN()const;
    VectorN* getPointPointer()const { return point; }
    Point& operator=(const Point & pPoint);
    bool operator==(const Point & point);
    bool isNull() const;
};

std::ostream& operator<<(std::ostream& os, const Point& dt);


#endif //SEARCHINGFORMINIMUMS_POINT_H
