//
// Created by student on 29.11.2020.
//

#ifndef SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
#define SEARCHINGFORMINIMUMS_ALGORITHMTEST_H


#include <string>
#include "VectorN.h"
#include "Algorithm.h"
#include "assert.h"

class AlgorithmTest: Algorithm {
public:
    AlgorithmTest(std::string fun):
        Algorithm(fun)
    {

    }

    void runTests(){
        testGoToMaximum();
        testGoToMinimum();
    }

    void testGoToMaximum(){
        // dane wejsciowe: f(a,b) = -a^2-b^2; start=(-155.13, 905.23); kierunek=grad;
        std::cout << "Test funkcji goToMaximum(start, kierunek, poczatkowyLength)\nf(a,b) = -a^2-b^2; start=(-15, 45); kierunek=grad\n";
        VectorN start(2);
        start.setNVal(0, -155.13);
        start.setNVal(1, 905.23);
        Algorithm algorithm("-a^2-b^2");
        VectorN grad=algorithm.function.getGradient(start);

        VectorN max(algorithm.goToMaximum(start, grad, 200));
        VectorN expected(2); // (0,0)
        assert(expected==max);

        std::cout << "Oczekiwane maksimum = " << expected << "\t znalezione maksimum = " << max << "\n\n";
    }

    void testGoToMinimum() {
        // dane wejsciowe: f(a,b) = a^2+b^2; start=(-15, 45); kierunek=grad;
        std::cout << "Test funkcji goToMinimum(start, kierunek, poczatkowyLength)\nf(a,b) = a^2+b^2; start=(-15, 45); kierunek=grad\n";
        VectorN start(2);
        start.setNVal(0, -154.24);
        start.setNVal(1, 450.7995);
        Algorithm algorithm("a^2+b^2", start);
        VectorN grad = algorithm.function.getGradient(start);
        //std::cout <<"\n" << grad <<"\n";

        VectorN min(algorithm.goToMinimum(start, grad.multiply(-1), 0.01)); // z bardzo malym krokiem startowym nie dojdziemy do minimum, ale to nic
        VectorN expected(2);// expected=(0,0)
        VectorN moveVector = min - start;   // wektor o ktory sie przesunelismy
        VectorN expected2(start+grad.multiply(-1/grad.getNorm()).multiply(moveVector.getNorm()));

        // albo osiagnelismy minimum, albo kierowalismy sie wzdluz gradientu i przekroczylismy limit iteracji
        assert( expected == min || expected2 == min );

        std::cout << "Oczekiwane minimum = {" << expected << "; " << expected2 << "}\t Znalezione minimum = " << min ;
    };
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
