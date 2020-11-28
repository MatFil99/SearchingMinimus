#include "MinimumsList.h"
#include "VectorN.h"
#include <iterator>

#include "VectorN.h"

bool MinimumsList::exists(Point *point ) {
    // check if point exist in list
    std::vector<Point>::iterator minLocal = listMin.begin();
    bool exist = false;
    while(minLocal < listMin.end() && exist == false){
        if( minLocal.base() == point ) exist = true;
    }
    return exist;
}

bool MinimumsList::addMinimumToList(Point point) {
    if(this->exists(&point)){
        return false; // minimum exists, not adding
    }
    Point p(point);
    this->getListMin().push_back(p);
}

std::vector<Point> MinimumsList::getListMin() { return listMin; }

void MinimumsList::printList() {
    for(std::vector<Point>::iterator it = listMin.begin(); it != listMin.end(); it++ ){
        //std::cout static_cast<Point>(it);
    }
}