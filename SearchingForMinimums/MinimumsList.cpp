#include "MinimumsList.h"
#include "VectorN.h"
#include <iterator>

#include "VectorN.h"

int MinimumsList::exists(Point point ) {
    // check if point exist in list
    int exist = -1;
    for(int i=0; i<listMin.size() && exist==-1; ++i) {
        if (listMin.at(i) == point) exist = i;
    }
    return exist;
}

void MinimumsList::addMinimumToList(Point point) {

    if (point.isNull())
        return;
    int index = this->exists(point);
    if(index!=-1){
        if( point.getValue()<listMin.at(index).getValue() ){
            listMin.at(index) = point;
        }
         // minimum exists, not adding
         std::cout << index;
    }{
        Point p(point);
        listMin.push_back(p);
    }
}

std::vector<Point>& MinimumsList::getListMin() { return listMin; }

void MinimumsList::printList() {
    for(std::vector<Point>::iterator it = listMin.begin(); it < listMin.end(); it++ ){
        std::cout << *it;
    }
}