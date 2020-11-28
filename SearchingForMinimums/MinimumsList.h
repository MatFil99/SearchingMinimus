#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    int current=0;
    std::vector<Point> listMin;

    int exists(Point point );

    int getCurrent(){ return current; }
    int incrementCurrent() { ++current; }
public:
    void addMinimumToList( Point point );
    std::vector<Point> & getListMin();

    void addElementToList(Point p);
    void printList();
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
