
#include "Algorithm.h"

#include <float.h>

double derivative(Function function, VectorN point, VectorN direction, double stepLength = DBL_MIN ){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN start = point - step;
    VectorN end = point + step;
    return (function.getValue(end) - function.getValue(start))/(2*stepLength);
}

Point Algorithm::searchOneMinimum(VectorN start) {
    VectorN gradient = function.getGradient(start), zero(function.getVarNum());
    double stepLength = 0.01;
    while(gradient != zero){
        VectorN step = gradient.multiply(-1*stepLength);
        start = start+step;
        gradient = function.getGradient(start);
    }
    return Point(start, function.getValue(start));
}

VectorN Algorithm::goToMaximum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    double val[1];
    do {
        start = start + step;
        val[0] = {derivative(function, start, direction)};
    } while(VectorN(1, val ) != zero);
    return start;
}

void Algorithm::leaveMinimum(VectorN start) {
    double stepLength = 0.01;
    VectorN max(function.getVarNum());
    for (int i = 0; i < function.getVarNum(); ++i){
        VectorN direction(function.getVarNum()) ;
        direction.setNVal(i, 1);
        max = goToMaximum(start, direction, stepLength);
        max = max + direction.multiply(stepLength);

        minList.addMinimumToList(searchOneMinimum(max));
        direction.setNVal(i, -1);
        max = goToMaximum(start, direction, stepLength);
        max = max + direction.multiply(stepLength);
        minList.addMinimumToList(searchOneMinimum(max));
    }
}

void Algorithm::searchAllMinimums() {
    VectorN startSearching = startPoint;
    int iteration = 0;
    int firstNotLeftMinimum = 0; //indeks na pierwsze minimum, ktorego nie opuscilismy w celu znalezienia kolejnych

    Point foundMinimum = searchOneMinimum(startSearching);
    while(firstNotLeftMinimum < minList.getListMin().size() && iteration < limitIteration ){
        leaveMinimum(minList.getListMin().at(firstNotLeftMinimum).getVectorN());
        ++firstNotLeftMinimum;
    }

    do{

    } while(firstNotLeftMinimum < minList.getListMin().size() && iteration < limitIteration);
}



