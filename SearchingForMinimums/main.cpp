#include <iostream>

#include <string>
#include "Algorithm.h"
#include "VectorN.h"
#include "Point.h"

#include "AlgorithmTest.h"

int main()
{
    std::string function;
    int maxLeave = 0;
    int divider;
    double precisionOptimum;
    double startBeta;
    double acceptableEstimation;
    std::cout << std::endl << "Funkcja: " << std::endl;
    std::cin >> function;

    std::cout << std::endl << "Parametr MAXLEAVE: ";
    std::cin >> maxLeave;
    std::cout <<std::endl << "Parametr DIVIDER: ";
    std::cin >> divider;
    std::cout << std::endl << "Parametr PRECISION_OPTIMUM: ";
    std::cin >> precisionOptimum;
    std::cout << std::endl << "Parametr STARTBETA ";
    std::cin >> startBeta;
    std::cout << std::endl << "Parametr ACCEPTABLEESTIMATION";
    std::cin >> acceptableEstimation;

    Algorithm algorithm(function, divider, maxLeave, precisionOptimum, startBeta, acceptableEstimation);
    VectorN start(algorithm.function.getVarNum());
    std::cout << "Punkt startowy:" ;
    for (int i = 0 ; i < algorithm.function.getVarNum(); ++i){
        std::cout << std::endl << "Wspolrzedna" << i << ": ";
        double xi;
        std::cin >> xi;
        start.setNVal(i, xi);
    }

    algorithm.searchAllMinimums(start);
    std::cout << std::endl << "Lista znalezionych minimow lokalnych: " << std::endl;
    algorithm.minList.printList();
    std::cout << std::endl << "Optimum (najmniejsze znalezione minimum lokalne): " << std::endl;
    std::cout << algorithm.getFoundOptimum();
    return 0;
}
