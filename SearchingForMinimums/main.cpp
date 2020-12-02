#include <iostream>

#include <string>
#include "Algorithm.h"
#include "VectorN.h"
#include "Point.h"

#include "AlgorithmTest.h"


int main()
{

    
        // Algorithm a = Algorithm("x^2+y^2", divider, leaving_limit, precision_optimum, start_beta, acceptable_estimation);
        // VectorN start = VectorN(2);
        // start.setNVal(0, x1);
        // start.setNVal(1, x2);
        // a.searchAllMinimums(start);
        // a.getMinList().printList();
        // std::cout << a.getFoundOptimum();
        // std::cout << "Podaj wszystkie parametry algorytmu\n";
    
    AlgorithmTest algTest;
    algTest.runTests();

    // std::string function;
    // int maxLeave = 0;

    // std::cout << std::endl << "Funkcja: " << std::endl;
    // std::cin >> function;

    // std::cout << "Maksymalna liczba optimow 'do opuszczenia' w celu poszukiwania nastepnych"
    // << std::endl << "(wiecej oznacza dluzsze poszukiwania):" <<std::endl;
    // Algorithm algorithm(function);
    // VectorN start(algorithm.function.getVarNum());
    // std::cout << "Punkt startowy:" ;
    // for (int i = 0 ; i < algorithm.function.getVarNum(); ++i){
    //     std::cout << std::endl << "Wspolrzedna " << i << ": ";
    //     double xi;
    //     std::cin >> xi;
    //     start.setNVal(i, xi);
    // }
    // algorithm.searchAllMinimums(start);
    // std::cout << std::endl << "Lista znalezionych minimow lokalnych: " << std::endl;
    // algorithm.minList.printList();
    // std::cout << std::endl << "Optimum (najmniejsze znalezione minimum lokalne): " << std::endl;
    // std::cout << algorithm.getFoundOptimum();

    return 0;
}
