#include <iostream>
#include <string>
#include "Algorithm.h"
#include "VectorN.h"
#include "Point.h"


int main()
{
    std::string function;
    int maxLeave = 0;

    std::cout << std::endl << "Funkcja: " << std::endl;
    std::cin >> function;

    std::cout << "Maksymalna liczba optimow 'do opuszczenia' w celu poszukiwania nastepnych"
    << std::endl << "(wiecej oznacza dluzsze poszukiwania):" <<std::endl;
    Algorithm algorithm(function);
    VectorN start(algorithm.function.getVarNum());
    std::cout << "Punkt startowy:" ;
    for (int i = 0 ; i < algorithm.function.getVarNum(); ++i){
        std::cout << std::endl << "Wspolrzedna " << i << ": ";
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
