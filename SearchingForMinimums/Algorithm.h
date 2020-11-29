#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
    MinimumsList minList;
    Function function;
    VectorN startPoint;
    int limitIterations = 50; // maksymalna liczba prob poszukiwania minimum
    int maxIterations = 50000;
    double beta=START_BETA;

    const double PENALTY = 2; // kara za przekroczenie minimum
    const double MAXREWARD = 1.5; // nagroda za znalezienie mniejszej wartosci i uzyskanie pochodnej ponad 1.5 raza lepszej (mniejszej)
    const double MAX_BETA = 4;
    const double START_BETA = 0.01;
protected:
    VectorN goToMaximum(VectorN start, VectorN direction, double stepLength);
    VectorN goToMinimum(VectorN start, VectorN grad, double stepLength);

    bool checkIfMinimum(VectorN optimumCandidate);

public:
    Algorithm(std::string f, VectorN s );   // jesli chcesz, mozesz podac punkt poczatkowy, ale musisz znac wymiar problemu
    Algorithm(std::string f );  // jesli nie podasz punktu poczatkowego, wybierzemy standardpwy/lub wylosujemy

    void searchAllMinimums(VectorN start);    //
    Point searchOneMinimum(VectorN start);    // znajduje pojedyncze minimum

    void leaveMinimum(VectorN start);

    MinimumsList getMinList(){ return minList; }

    VectorN getStartPoint(){ return startPoint; }

};


#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
