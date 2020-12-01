
#include "Algorithm.h"
#include <algorithm>
#include <cstdlib>


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
    start = leaveMaxArea(start);
    VectorN gradient = function.getGradient(start);
    double stepLength = START_BETA;
    unsigned int count = 0;
    while(gradient.getNorm() > PRECISION_OPTIMUM && count < MAX_ITERATIONS ){

        VectorN prev = start;
        start = goToMinimum(start, gradient.multiply(-1), stepLength);   // znajduje minimum w kierunku gradientu, minimalizuje funkcje wzgledem beta
        stepLength = std::max((start-prev).getNorm()/4, MIN_BETA);  //

        gradient = function.getGradient(start);
        ++count;

//        if( prev == start ) break;
    }
    if (count >= MAX_ITERATIONS && !ifMinimum(start)) {// przyjmujemy, ze jesli po setnym kroku nie uzyskalismy gradientu zerowego (bliskiego 0) to nie znajdziemy minimum
        std::cout << "zwrocono pusty punkt\n";
        Point p;
        return p;
    }else
    return Point(start, function.getValue(start));
}

VectorN Algorithm::goToMinimum(VectorN start, VectorN direction, double stepLength){
    VectorN step = direction.multiply(1/direction.getNorm()).multiply(stepLength);
    VectorN zero(1);
    unsigned int count = 0;
    if(derivative(function, start + step, direction, PRECISION_DERIVATIVE) > 0 ){ return start; } /* w tym kierunku funkcja rosnie */
    while (step.getNorm() > PRECISION_OPTIMUM/2 && count < LIMIT_ITERATIONS ){
        if ( derivative(function, start + step, direction, PRECISION_DERIVATIVE) > 0 ){
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
    if (derivative(function, start+step, direction, PRECISION_DERIVATIVE) < 0) {/* zly kierunek - funkcja maleje */ return start; }
    while (step.getNorm() > PRECISION_OPTIMUM && count < LIMIT_ITERATIONS) {
        if ( derivative(function, start+step, direction, PRECISION_DERIVATIVE) < 0 ){
            step = step.multiply(0.5);
            // i nie idz kroku do przodu - zrob mniejszy krok lub zakoncz szukanie
        }else {
            start = start + step;
        }
        ++count;
    }
    if(count == LIMIT_ITERATIONS) {
        return VectorN();
    }
    return start ;
}

VectorN Algorithm::leaveMaxArea(VectorN point ) { // zwraca wektor z wartosciami 0 - gdy dany jest to kierunkowe min i 1 gdy dany kierunek nie jest minimum
    VectorN result(point), nextPoint(point.getSize()), prevPoint(point.getSize());
    int n = 0;
    double step = START_BETA, deriv=0;
    for (int i =0; i<point.getSize(); ++i){
        VectorN direction(point.getSize());
        direction.setNVal(i, 1);
        deriv = derivative(function, result, direction, PRECISION_DERIVATIVE );
        while( deriv > -PRECISION_OPTIMUM && deriv<=0 && n++<MAX_ITERATIONS){
            deriv = derivative(function, result, direction, PRECISION_DERIVATIVE );
            result = result + direction.multiply(step);
        }
    }
    return result;
}

bool Algorithm::ifMinimum(VectorN minCandidate) {
    double prevVal = 0, nextVal = 0, minCandidateVal = function.getValue(minCandidate);
    double step = START_BETA;
    for (int i=0; i<minCandidate.getSize(); ++i){
        VectorN v(minCandidate.getSize());
        v.setNVal(i, 1);
        prevVal = function.getValue(minCandidate - v.multiply(step));
        nextVal = function.getValue(minCandidate + v.multiply(step));
        if( minCandidateVal-prevVal>ACCEPTABLE_ESTIMATION || minCandidateVal-nextVal>ACCEPTABLE_ESTIMATION ){
            return false;
        }
    }
    return true;
}

void Algorithm::leaveMinimum(VectorN start) {
    double stepLength = 0.1;
    VectorN max(function.getVarNum());
    for (int i = 0; i < function.getVarNum(); ++i){
        VectorN direction(function.getVarNum()) ;
        direction.setNVal(i, 1);
        max = goToMaximum(start, direction, stepLength);
        if(!max.isNull()) {
            while (derivative(function, max, direction, PRECISION_DERIVATIVE) > -1 * PRECISION_OPTIMUM) {
                max = max + direction.multiply(stepLength);
            }
            minList.addMinimumToList(searchOneMinimum(max));
            direction.setNVal(i, -1);
        }
        max = goToMaximum(start, direction, stepLength);
        if(!max.isNull()) {
            while (derivative(function, max, direction, PRECISION_DERIVATIVE) > -1 * PRECISION_OPTIMUM) {
                max = max + direction.multiply(stepLength);
            }
            minList.addMinimumToList(searchOneMinimum(max));
        }
    }
}


void Algorithm::searchAllMinimums(VectorN start) {
    int n = 0;
    VectorN zero(start.getSize());
    if(function.getGradient(start)==zero) {
        start = randomStartPoint(start, 10);
        if( function.getGradient(start)==zero) { std::cout << "Prawdopodobnie funkcja stala"; return;}
    }
    Point minimum = searchOneMinimum(start);
    minList.addMinimumToList(minimum);
    while (n < minList.getListMin().size() && n < 10) {
        leaveMinimum(minList.getListMin().at(n).getVectorN());
        ++n;
    }
}

VectorN Algorithm::randomStartPoint(VectorN point, int rangeLength){
    int lots = 200;
    srand((NULL));
    VectorN randomV(point.getSize()), gradient(point.getSize()), zero(point.getSize());
    do {
        for (int i = 0; i < point.getSize(); ++i) {
            randomV.setNVal(i, point.getNVal(i) + rand() % rangeLength);
        }
        gradient = function.getGradient(randomV);
        --lots;
    }while(gradient==zero && lots>0);
    return randomV;
}


