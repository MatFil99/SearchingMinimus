#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
public: // potem usun
    MinimumsList minList;
    Function function;
    VectorN startPoint;
//    int limitIterations = 1000000; // maksymalna liczba prob poszukiwania minimum

    const int LIMIT_ITERATIONS = 100000;            // maksymalna liczba iteracji w poszukiwaniu optimum kierunkowego
    const int MAX_ITERATIONS = 20;                   // maksymalna liczba wykonanych minimalizacji kierunkowych - zygzakow
    const double MIN_BETA = 0.0005;                  // minimalna wartosc kroku
    const double PRECISION_OPTIMUM = 0.00005;
    const double START_BETA = 0.05;
    const double PRECISION_DERIVATIVE = 0.0005;
    const double ACCEPTABLE_ESTIMATION = 0.05;


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
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
