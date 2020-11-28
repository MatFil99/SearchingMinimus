#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    std::vector<Point> listMin;

    int exists(Point point );

public:
    void addMinimumToList( Point point );
    std::vector<Point> & getListMin();

    void addElementToList(Point p);
    void printList();
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
