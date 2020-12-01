
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
    while(gradient != zero && count < 100 ){
        VectorN prev = start;
        start = goToMinimum(start, gradient, stepLength);   // znajduje minimum w kierunku gradientu, minimalizuje funkcje wzgledem beta
        VectorN step = gradient.multiply(-1*stepLength);
        start = start+step;
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
    double derivativeNext = 0; // = derivative(function, start + step, direction, PRECISION_DERIVATIVE);
    while (step.getNorm() > PRECISION_OPTIMUM && count < limitIterations ){
        derivativeNext = derivative(function, start + step, direction, PRECISION_DERIVATIVE);
        if ( derivativeNext > 0 ){
            step = step.multiply(0.5);
            // i nie idz kroku do przodu - zrob mniejszy krok lub zakoncz szukanie
        }else {
            start = start + step;
        }
        ++count;
    }
    std::cout << count <<std::endl;
    return start;
}

VectorN Algorithm::goToMaximum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    double derivativeNext = 0;
    while (step.getNorm() > PRECISION_OPTIMUM && count < limitIterations) {
        derivativeNext = derivative(function, start+step, direction, PRECISION_DERIVATIVE);
        if ( derivativeNext < 0 ){
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
    Point min(function.getVarNum(), 0);
    for (int i = 0; i < function.getVarNum(); ++i){
        VectorN direction(function.getVarNum()) ;
        direction.setNVal(i, 1);
        max = goToMaximum(start, direction, stepLength);
        max = max + direction.multiply(stepLength);
        min = searchOneMinimum(max);
        if (checkIfMinimum(min.getVectorN())){
            minList.addMinimumToList(searchOneMinimum(max));
        }
        direction.setNVal(i, -1);
        max = goToMaximum(start, direction, stepLength);
        max = max + direction.multiply(stepLength);
        min = searchOneMinimum(max);
        if (checkIfMinimum(min.getVectorN())){
            minList.addMinimumToList(searchOneMinimum(max));
        }
    }
}


void Algorithm::searchAllMinimums(VectorN start) {
    int iteration;
    int n = 0;
    Point optimum(searchOneMinimum(start));
    minList.addMinimumToList(optimum);
    while (n < minList.getListMin().size() && iteration < limitIterations) {
        ++iteration;
        leaveMinimum(minList.getListMin().at(n).getVectorN());
        ++n;
    }

}



