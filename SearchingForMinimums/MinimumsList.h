#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Point.h"
#include <vector>

class MinimumsList {
    std::vector<Point> listMin;
    bool * exists(double * tab);
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
