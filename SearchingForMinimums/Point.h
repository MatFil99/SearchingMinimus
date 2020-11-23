#ifndef SEARCHINGFORMINIMUMS_POINT_H
#define SEARCHINGFORMINIMUMS_POINT_H


#include "VectorN.h"
#include <iostream>

class Point {



    VectorN point = VectorN(0);
    double value;


    double getValue()const;
    bool operator==(const Point & point);

    Point& operator=(const Point & pPoint);

public:
    Point( Point *pPoint);
    Point();
    Point(VectorN &vectorN, double value);

    VectorN getVectorN()const;
};

std::ostream& operator<<(std::ostream& os, const Point& dt);


#endif //SEARCHINGFORMINIMUMS_POINT_H
