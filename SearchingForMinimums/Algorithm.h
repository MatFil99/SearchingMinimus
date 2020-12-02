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

    const unsigned int LIMIT_ITERATIONS = 100000;               // maksymalna liczba iteracji w poszukiwaniu optimum kierunkowego
    const unsigned int MAX_ITERATIONS = 20;                     // maksymalna liczba wykonanych minimalizacji kierunkowych - zygzakow
    const unsigned int LEAVE_MAXIMUM_AREA_ITERATIONS = 20;      // maksymalna liczba iteracji, podczas opuszczania maksimum
    const unsigned int DIVIDER = 4;
    const double PRECISION_OPTIMUM = 0.00005;                   // precyzja z jaka liczymy optimum (
    const double START_BETA = 0.05;                             // poczatkowy krok z jakim bedziemy sie przemieszczac szukajac minimum kierunkowego
    const double PRECISION_DERIVATIVE = 0.0005;                 // jest to wartosc delty x w pochodnej: f' = (f(x+delta)-f(x-delta))/2*delta
    const double ACCEPTABLE_ESTIMATION = 0.05;                  // akceptowalne oszacowanie minimum, stosowane do sprawdzania czy dany punkt mozna uznac za minimum

    Algorithm(std::string f );  // 

public:
    VectorN goToMaximum(VectorN start, VectorN direction, double stepLength);
    VectorN goToMinimum(VectorN start, VectorN grad, double stepLength);
    bool ifMinimum(VectorN minCandidate);
    void searchAllMinimums(VectorN start);    //
    Point searchOneMinimum(VectorN start);    // znajduje pojedyncze minimum



    MinimumsList getMinList(){ return minList; }

    VectorN getStartPoint(){ return startPoint; }

    VectorN leaveMaxArea(VectorN point);

    Point getFoundOptimum();
};

double derivative(Function& function, VectorN point, VectorN direction, double stepLength );

#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
