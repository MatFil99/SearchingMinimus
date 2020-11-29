
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
        start = goToMinimum(start, gradient, stepLength);   // znajduje minimum w kierunku gradientu, minimalizuje funkcje wzgledem beta
        //VectorN step = gradient.multiply(-1*stepLength);
        //start = start+step;
        gradient = function.getGradient(start);
    }
    return Point(start, function.getValue(start));
}

VectorN Algorithm::goToMinimum(VectorN start, VectorN grad, double stepLength ){
    double previousV = function.getValue(start), currentV=previousV-1;
    double currDerivative = -1, prevDerivative = 0;
    while( currentV < previousV ){
        currentV = function.getValue(start + grad.multiply(beta));
        if ( currentV > previousV ){
            beta /= PENALTY;
            return VectorN(start);
        } else{
            prevDerivative = derivative(function, start, grad);
            currDerivative = derivative(function, start+grad, grad);
            if( prevDerivative > currDerivative ){
                beta = std::min(beta*currDerivative/prevDerivative, beta*MAXREWARD);
                beta = std::min(beta, MAX_BETA);
            }else {
                beta /= (currentV/previousV);
            }
        }
        start = start + grad.multiply(beta);
    }
    return VectorN(start);
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
        leaveMinimum(minList.getListMin().at(n).getVectorN());
        ++n;
    }

}



