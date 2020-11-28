#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    int current=0;
    std::vector<Point> listMin;

    bool exists(Point *point );

    int getCurrent(){ return current; };
    int incrementCurrent() { ++current; };
public:
    bool addMinimumToList( Point point );
    std::vector<Point> getListMin();

    void printList();
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
