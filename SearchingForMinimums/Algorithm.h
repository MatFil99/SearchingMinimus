#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {

    MinimumsList minList;
    Function function;
    VectorN startPoint;
    int limitIteration = 50;

protected:
    VectorN goToMaximum(VectorN start, VectorN direction, double stepLength);

public:
    Algorithm(Function f, VectorN s );

    void searchAllMinimums();    //
    Point searchOneMinimum(VectorN start);    // znajduje pojedyncze minimum

    VectorN searchMaximumDirection(int direction, int maxIterations ); //
    void leaveMinimum(VectorN start);


};


#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
