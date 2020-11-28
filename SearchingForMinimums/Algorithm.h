//
// Created by student on 28.11.2020.
//

#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
    MinimumsList minList;
    Function function;
    VectorN startPoint;
public:
    Algorithm(Function f, VectorN s );

    void searchAllMinimums();    //
    Point searchOneMinimum();    // znajduje pojedyncze minimum

    VectorN searchMaximumDirection(int direction, int maxIterations); //
    void leaveMinimum();
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
