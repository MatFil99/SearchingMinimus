//
// Created by student on 29.11.2020.
//

#ifndef SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
#define SEARCHINGFORMINIMUMS_ALGORITHMTEST_H


#include <string>
#include "VectorN.h"
#include "Algorithm.h"

class AlgorithmTest: Algorithm {
public:
    AlgorithmTest(std::string fun):
        Algorithm(fun)
    {

    }

    void runTests(){
        testGoToMaximum();
    }

    void testGoToMaximum(){
        //Algorithm alg("x^2+y^2", 1);
        VectorN start(2);
        start.setNVal(0, -15);
        start.setNVal(1, 0);
        VectorN direction(2);
        direction.setNVal(0,1);
//        std::cout << start;
        VectorN min(goToMinimum(start, direction, 0.01));
        std::cout << min;
//        alg.getMinList().printList();
    }
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
