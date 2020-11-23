#ifndef SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
#define SEARCHINGFORMINIMUMS_MINIMUMSLIST_H

#include "Minimum.h"
#include <vector>

class MinimumsList {
    std::vector<Minimum> listMin;
    bool * exists(double * tab);
};


#endif //SEARCHINGFORMINIMUMS_MINIMUMSLIST_H
