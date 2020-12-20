#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    std::vector<Point> listMin;



public:
    void addMinimumToList( Point point );
    std::vector<Point> & getListMin();

    int exists( Point point );

    void addElementToList(Point p);
    void printList();
    Point getFoundOptimum();
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
