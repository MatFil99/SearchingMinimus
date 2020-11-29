//
// Created by student on 29.11.2020.
//

#ifndef SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
#define SEARCHINGFORMINIMUMS_ALGORITHMTEST_H


#include <string>
#include "VectorN.h"
#include "Algorithm.h"

class AlgorithmTest {
public:
    void runTests(){
        testGoToMaximum();
    }

    Algorithm& initializeAlg( std::string fun, int numVar=-1){
        if(numVar <= 0){
            Algorithm alg(fun);
            return alg;
        }else{
            Algorithm alg(fun, numVar);
            return alg;
        }
    }

    void testGoToMaximum(){
        Algorithm alg("(x-4)^2", 1);
        alg.searchAllMinimums(alg.getStartPoint());

        alg.getMinList().printList();
    }
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
