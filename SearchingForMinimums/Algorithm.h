#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
public:
    MinimumsList minList;
    Function function;
    VectorN startPoint;
//    int limitIterations = 1000000; // maksymalna liczba prob poszukiwania minimum

    const int LIMIT_ITERATIONS = 100000;            // maksymalna liczba iteracji w poszukiwaniu optimum kierunkowego
    const int MAX_ITERATIONS = 20;                  // maksymalna liczba wykonanych minimalizacji kierunkowych - zygzakow
    const double PRECISION_OPTIMUM = 0.00005;       // precyzja z jaka liczymy optimum (
    const double START_BETA = 0.05;                 // poczatkowy krok z jakim bedziemy sie przemieszczac szukajac minimum kierunkowego
    const double PRECISION_DERIVATIVE = 0.0005;     // jest to wartosc delty x w pochodnej: f' = (f(x+delta)-f(x-delta))/2*delta
    const double ACCEPTABLE_ESTIMATION = 0.05;      // akceptowalne oszacowanie minimum, stosowane do sprawdzania czy dany punkt mozna uznac za minimum

public:
    VectorN goToMaximum(VectorN start, VectorN direction, double stepLength);
    VectorN goToMinimum(VectorN start, VectorN grad, double stepLength);
    bool ifMinimum(VectorN minCandidate);
public:
    Algorithm(std::string f, VectorN s );   // jesli chcesz, mozesz podac punkt poczatkowy, ale musisz znac wymiar problemu
    Algorithm(std::string f );  // jesli nie podasz punktu poczatkowego, wybierzemy standardpwy/lub wylosujemy

    void searchAllMinimums(VectorN start);    //
    Point searchOneMinimum(VectorN start);    // znajduje pojedyncze minimum

    void leaveMinimum(VectorN start);

    MinimumsList getMinList(){ return minList; }

    VectorN getStartPoint(){ return startPoint; }

    VectorN leaveMaxArea(VectorN point);

    VectorN randomStartPoint(VectorN point, int rangeLength);

    Point getFoundOptimum();
};

double derivative(Function& function, VectorN point, VectorN direction, double stepLength );

#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
