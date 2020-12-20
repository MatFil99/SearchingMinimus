#ifndef SEARCHINGFORMINIMUMS_ALGORITHM_H
#define SEARCHINGFORMINIMUMS_ALGORITHM_H


#include "MinimumsList.h"
#include "Function.h"

class Algorithm {
public:
    MinimumsList minList;
    Function function;
//    int limitIterations = 1000000; // maksymalna liczba prob poszukiwania minimum

    unsigned int LIMIT_ITERATIONS = 100000;               // maksymalna liczba iteracji w poszukiwaniu optimum kierunkowego
    unsigned int MAX_ITERATIONS = 30;                     // maksymalna liczba wykonanych minimalizacji kierunkowych - zygzakow
    unsigned int LEAVE_MAXIMUM_AREA_ITERATIONS = 20;      // maksymalna liczba iteracji, podczas opuszczania maksimum
    unsigned int LEAVE_MINIMUM_AREA_ITERATIONS = 1000;    // maksymalna liczba iteracji opuszczania obszaru minimum
    unsigned int BETA_DIVIDER = 4;
    unsigned int LEAVING_LIMIT = 20;                      // maksymalna liczba minimow, ktore opuszczamy w celu poszukiwania nastpnych
    double PRECISION_OPTIMUM = 0.00005;                   // precyzja z jaka liczymy optimum (
    double START_BETA = 0.05;                             // poczatkowy krok z jakim bedziemy sie przemieszczac szukajac minimum kierunkowego
    double PRECISION_DERIVATIVE = 0.0000005;                 // jest to wartosc delty x w pochodnej: f' = (f(x+delta)-f(x-delta))/2*delta
    double ACCEPTABLE_ESTIMATION = 0.05;                  // akceptowalne oszacowanie minimum, stosowane do sprawdzania czy dany punkt mozna uznac za minimum
    
    Algorithm(std::string f );  // 
    Algorithm(std::string f, int divider, int leaving_limit, double precision_optimum, double start_beta, double acceptable_estimation);
    Algorithm(std::string f, int divider, int leaving_limit, double precision_optimum, double start_beta, double acceptable_estimation, int dimVec);

    VectorN goToMaximum(VectorN start, VectorN direction, double stepLength);   // szuka maksimum w kierunku direction
    VectorN goToMinimum(VectorN start, VectorN direction, double stepLength);        // szuka minimum w kierunku 
    bool ifMinimum(VectorN minCandidate);                              // oszacowuje, czy punkt mozna uznac za minimum
    void searchAllMinimums(VectorN start);    // glowny program szukajacy wielu minimum - w zaleznosci
    Point searchOneMinimum(VectorN start);    // znajduje pojedyncze minimum

    VectorN randomStartPoint(VectorN point, int rangeLength);
    void leaveMinimum(VectorN start);
    MinimumsList getMinList(){ return minList; }

    VectorN leaveMaxArea(VectorN point, VectorN direction);

    Point getFoundOptimum();

    const double PRECISION_LEAVING_MAXIMUM = 0.01;
};

double derivative(Function& function, VectorN point, VectorN direction, double stepLength );

#endif //SEARCHINGFORMINIMUMS_ALGORITHM_H
