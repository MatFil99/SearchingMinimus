
#include "Algorithm.h"
#include <algorithm>
#include <float.h>


Algorithm::Algorithm(std::string f, VectorN s):
    function(f),
    startPoint(1),
    minList()
{
}

Algorithm::Algorithm(std::string f):
    function(f),
    startPoint(function.getVarNum()),
    minList()
{
    // tutaj mozna wylosowac punkt
}



double derivative(Function& function, VectorN point, VectorN direction, double stepLength ){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN start = point - step;
    VectorN end = point + step;
    return (function.getValue(end) - function.getValue(start))/(2*stepLength);
}

Point Algorithm::searchOneMinimum(VectorN start) {
    VectorN gradient = function.getGradient(start), zero(function.getVarNum());
    double stepLength = 0.2;
    unsigned int count = 0;
    while(gradient.getNorm() > PRECISION_OPTIMUM && count < limitIterations ){
        start = goToMinimum(start, gradient.multiply(-1), stepLength);   // znajduje minimum w kierunku gradientu, minimalizuje funkcje wzgledem beta
        gradient = function.getGradient(start);
        ++count;
    }
    if (count == limitIterations)
        return Point();
    else
    return Point(start, function.getValue(start));
}

void Algorithm::adoptBetaMin(double prevV, double currV, double prevD, double currD) {

}

VectorN Algorithm::goToMinimum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    while (step.getNorm() > PRECISION_OPTIMUM/2 && count < limitIterations ){
        if (derivative(function, start + step, direction, PRECISION_DERIVATIVE) > 0 ){
            step = step.multiply(0.5);
            // i nie idz kroku do przodu - zrob mniejszy krok lub zakoncz szukanie
        }else {
            start = start + step;
        }
        ++count;
    }
    return start;
}

VectorN Algorithm::goToMaximum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    while (step.getNorm() > PRECISION_OPTIMUM && count < limitIterations) {
        if ( derivative(function, start+step, direction, PRECISION_DERIVATIVE) < 0 ){
            step = step.multiply(0.5);
            // i nie idz kroku do przodu - zrob mniejszy krok lub zakoncz szukanie
        }else {
            start = start + step;
        }
        ++count;
    }
    return start ;
}

bool Algorithm::checkIfMinimum(VectorN minimumCandidate ) {
    double minCandidateVal = function.getValue(minimumCandidate);
    double step = START_BETA;
    for(int i=0; i<function.getVarNum(); ++i ){
        VectorN direction(function.getVarNum());
        direction.setNVal(i, 1);
        VectorN nextPoint = minimumCandidate+direction.multiply(step);
        if ( function.getValue(nextPoint) - minCandidateVal < 0 ){ // ACCEPTABLEDEVIATI
            return false;
        }
    }
    return true;
}

void Algorithm::leaveMinimum(VectorN start) {
    double stepLength = 0.01;
    VectorN max(function.getVarNum());
    for (int i = 0; i < function.getVarNum(); ++i){
        VectorN direction(function.getVarNum()) ;
        direction.setNVal(i, 1);
        max = goToMaximum(start, direction, stepLength);
        while (derivative(function, max, direction, PRECISION_DERIVATIVE) > -1*PRECISION_OPTIMUM){
            max = max + direction.multiply(stepLength);
        }
        minList.addMinimumToList(searchOneMinimum(max));
        direction.setNVal(i, -1);
        max = goToMaximum(start, direction, stepLength);
        while (derivative(function, max, direction, PRECISION_DERIVATIVE) > -1*PRECISION_OPTIMUM){
            max = max + direction.multiply(stepLength);
        }
        minList.addMinimumToList(searchOneMinimum(max));
    }
}


void Algorithm::searchAllMinimums(VectorN start) {
    int n = 0;
    Point optimum = searchOneMinimum(start);
    minList.addMinimumToList(optimum);
    while (n < minList.getListMin().size() && n < 10) {
        leaveMinimum(minList.getListMin().at(n).getVectorN());
        ++n;
    }

}



