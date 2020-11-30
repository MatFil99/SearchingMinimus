
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
    double stepLength = 0.01;
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

/*
VectorN Algorithm::goToMinimum(VectorN start, VectorN grad, double stepLength ){
    VectorN resultMin(start.getSize()), prevPoint(start.getSize());
    double lastStepLenght = PRECISION_OPTIMUM+1, previousV = function.getValue(start), currentV=function.getValue(start+grad.multiply(beta));
    double currDerivative = derivative(function, start, grad, PRECISION_DERIVATIVE), prevDerivative = derivative(function, start, grad, PRECISION_DERIVATIVE);
    int iterations = 0;
    while( Algorithm::MAX_ITERATIONS > iterations++ && (lastStepLenght > PRECISION_OPTIMUM || currDerivative<0 ) ){
        if ( currDerivative > 0 && ( lastStepLenght > PRECISION_DERIVATIVE) || currentV>previousV ){
            // "cofnij" sie do poprzedniego punktu i zrob mniejszy krok
            beta = START_BETA; // minimalny krok
            std::cout << prevPoint << "<-- prev Point \t" << start << "<-- curr Point\n";
            lastStepLenght = (start - prevPoint).getNorm();
            start = prevPoint+grad.multiply(beta);
            currentV = function.getValue(start);
            currDerivative = derivative(function, start, grad, PRECISION_DERIVATIVE);
        }else{
            if ( currentV < previousV ){
                if (currDerivative < prevDerivative){
                    beta = std::min(MAX_BETA, beta*currDerivative/prevDerivative);
                }else {
                    beta = std::min(MAX_BETA, beta*SMALL_REWARD);
                }
            }
            prevPoint = start;
            previousV = currentV;
            start = start + grad.multiply(beta);
            currentV = function.getValue(start);
            prevDerivative = currDerivative;
            currDerivative = derivative(function, start, grad, PRECISION_DERIVATIVE );
        }
        std::cout << currentV << " " << previousV << " " << currDerivative << " " << start << " " << std::endl;
//        std::cout << "currDerivative = " << currDerivative << "\t prevDerivative = " <<prevDerivative << "\t beta = " << beta << std::endl;
    }

    std::cout << iterations << " " <<prevPoint << " " << start <<  " " << previousV << " " << currentV << std::endl;
    if( (iterations == Algorithm::MAX_ITERATIONS && previousV > currentV) || ( previousV < currentV && iterations <= 2) ){
        // jesli funkcja caly czas maleje lub gdy funkcja w danym kierunku rosnie (wtedy najpierw znajdz maksimum w tym kierunku)
        resultMin = VectorN(VectorN::NULL_VECTOR);
    }else{
        resultMin = start;
    }
    return resultMin;
}*/

void Algorithm::adoptBetaMin(double prevV, double currV, double prevD, double currD) {

}

VectorN Algorithm::goToMinimum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    double val[1];
    while (step.getNorm() > PRECISION_OPTIMUM && count < limitIterations) {
        while (derivative(function, start, direction, PRECISION_DERIVATIVE) <= 0 && count < limitIterations ) {
            start = start + step;
            ++count;
        }
        step = step.multiply(1/2);
    }
    return start ;
}

VectorN Algorithm::goToMaximum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    double val[1];
    while (step.getNorm() > PRECISION_OPTIMUM && count < limitIterations) {
        do {
            start = start + step;
            ++count;
        } while (derivative(function, start, direction, PRECISION_DERIVATIVE) >= 0 && count < limitIterations );
        step = step.multiply(1/2);
    }
    return start ;
}

/*VectorN Algorithm::goToMinimum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    double val[1];
    do {
        start = start + step;
    } while(derivative(function, start, direction, PRECISION_DERIVATIVE) < 0);
    return start - step;
}*/

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



