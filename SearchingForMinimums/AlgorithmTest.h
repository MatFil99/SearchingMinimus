//
// Created by student on 29.11.2020.
//

#ifndef SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
#define SEARCHINGFORMINIMUMS_ALGORITHMTEST_H


#include <string>
#include "VectorN.h"
#include "Algorithm.h"
#include "assert.h"

class AlgorithmTest {
public:
    void runTests(){
//        testGoToMaximum();
//        testGoToMinimum();
//        testSearchOneMinimum();
        testAddingToList();
//        testSearchAllMinimums();
    }


    void testAddingToList(){
        Algorithm a("x^2+y^2+z^2+w^2");
        VectorN v1(4);
        v1.setNVal(0, 4);
        VectorN v2(4);
        v2.setNVal(1, 4);

        Point p1(v1, 10), p2(v2, 12);

        a.minList.addMinimumToList(p1);
        a.minList.addMinimumToList(p2);

        a.minList.printList();


    }

    void testSearchOneMinimum(){
        Algorithm algorithm("x^2+y^2");
        VectorN start(2);
        start.setNVal(0, 100);
        start.setNVal(1, -123);

        Point minimum(algorithm.searchOneMinimum(start));
        std::cout << minimum;
//        if(minimum.getVectorN().ifNull())
//            std::cout << minimum;
    }

    void testGoToMaximum(){
        // testy funkcji goToMaximum
        std::cout << "= = = = = = = = = = = = = = = = = \n=\t testy funkcji goToMaximum  =\n= = = = = = = = = = = = = = = = = \n";
        VectorN start(2), expected(2);

        // test 1
        start.setNVal(0, -155.13);
        start.setNVal(1, 905.23);
        universalTestGoToMaximum( "-x^2-y^2", start, expected, 0.01);

        // test 2
        start.setNVal(0, 0.7);
        start.setNVal(1, 15);
        universalTestGoToMaximum("-a^2-b^2", start, expected);
    }

    void testGoToMinimum() {
        std::cout << "= = = = = = = = = = = = = = = = = \n=\t testy funkcji goToMinimum  =\n= = = = = = = = = = = = = = = = = \n";
        VectorN start(2), expected(2);
        start.setNVal(0, -154.24);
        start.setNVal(1, 450.7995);
        //test 1
        universalTestGoToMinimum( "a^2+b^2", start, expected );

        //test 2
        start.setNVal( 0, 0.05);
        start.setNVal(1, -0.006);
        universalTestGoToMinimum("a^2+b^2", start, expected);

        // test 3
        VectorN start1N(1);
        start1N.setNVal(0, 15);
        universalTestGoToMinimum("x^2", start1N, expected);
    }

    void universalTestGoToMinimum(const std::string & function, const VectorN & start, const VectorN & expected, double stepLength=10 ){
        std::cout << "f = " << function << "; start= " << start << " ; kierunek=grad\n";

        Algorithm algorithm(function);
        VectorN grad = algorithm.function.getGradient(start);
        VectorN min(algorithm.goToMinimum(start, grad.multiply(1), stepLength)); // z bardzo malym krokiem startowym nie dojdziemy do minimum, ale to nic
        VectorN moveVector = min - start;   // wektor o ktory sie przesunelismy
        VectorN expected2(start+grad.multiply(-1/grad.getNorm()).multiply(moveVector.getNorm()));

        // albo osiagnelismy minimum, albo kierowalismy sie wzdluz gradientu i przekroczylismy limit iteracji
        //assert( expected == min || expected2 == min && start != min );


        std::cout << "Oczekiwane minimum = {" << expected << "; " << expected2 << "}\t Znalezione minimum = " << min << "\n\n" ;
    }

    void universalTestGoToMaximum(const std::string & function, const VectorN & start, const VectorN & expected, double stepLength=10){
        std::cout << function << "; start= " << start << " ; kierunek=grad\n";

        Algorithm algorithm(function);
        VectorN grad = algorithm.function.getGradient(start);
        VectorN max(algorithm.goToMaximum(start, grad, stepLength)); // z bardzo malym krokiem startowym nie dojdziemy do minimum, ale to nic
        VectorN moveVector = max - start;   // wektor o ktory sie przesunelismy
        VectorN expected2(start+grad.multiply(1/grad.getNorm()).multiply(moveVector.getNorm()));

        // albo osiagnelismy minimum, albo kierowalismy sie wzdluz gradientu i przekroczylismy limit iteracji
        assert( expected == max || expected2 == max && start != max );

        std::cout << "Oczekiwane maksimum = {" << expected << "; " << expected2 << "}\t Znalezione maksimum = " << max << "\n\n" ;

    }

//    void testSearchOneMinimum(){
//        VectorN start(2);
//        start.setNVal(0, -4.72225);
//        start.setNVal(1, -3.14189);
//        Algorithm algorithm("sin(x)+cos(y)");
//        double val[1] = {algorithm.searchOneMinimum(start).getValue()};
//        std::cout << std::endl << val[0];
//        double expected[1] = {-2};
//        assert(VectorN(1, val) == VectorN(1, expected));
//    }

    void testSearchAllMinimums(){
        VectorN start(2);
        start.setNVal(0, 0);
        start.setNVal(1, 40);
//        start.setNVal(5, 20);
        Algorithm algorithm("cos(x)*sin(x)");
        algorithm.searchAllMinimums(start);
        algorithm.getMinList().printList();
    }
};


#endif //SEARCHINGFORMINIMUMS_ALGORITHMTEST_H
