#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
public: // potem usun
    MinimumsList minList;
    Function function;
    VectorN startPoint;
    int limitIterations = 1000000; // maksymalna liczba prob poszukiwania minimum

    double beta=START_BETA;

    const double PENALTY = 2; // kara za przekroczenie minimum
    const double SMALL_REWARD = 1.05; // nagroda za znalezienie mniejszej wartosci i uzyskanie pochodnej ponad 1.5 raza lepszej (mniejszej)
    const double MAX_BETA = 4;
    const double MIN_BETA = 0.0005;
    const double PRECISION_OPTIMUM = 0.0005;

    constexpr static const double START_BETA = 0.05;
    const double PRECISION_DERIVATIVE = 0.0005;
    static const int MAX_ITERATIONS = 5;
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
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
