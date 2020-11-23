#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    std::vector<Point> listMin;
    bool exists( Point * point );

    bool addMinimumToList( Point * point );

};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
