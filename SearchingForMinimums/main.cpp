
#include "fparser4.5.2/fparser.hh"

#include <iostream>
#include <string>
//#include "TestPoint.h"
#include "FunctionTest.h"

#include "MinimumsList.h"
#include "Algorithm.h"
#include "AlgorithmTest.h"

//Useless comment

//class A{
//public:
//    int *i;
//
//    A(A const &a1)
//        //i(new int(*a1.i))
//    {
//        i = new int(*a1.i);
//        std::cout <<"A(A const &a1)";
//    }
//
//    A(int i1)
////        i(new int(i1))
//    {
//        i = new int(i1);
//        std::cout << "A(int i1)";
//    }

//    int i;
//    A(A const &a1):
//            i(a1.i)
//    {
//    }
//
//    A(int i1):
//            i(i1)
//    {}
//
//};
//
//class B{
//
//public:
//    A zwrocA(){
//        A a(5);
//        //return reinterpret_cast<const A &>(a);
//        return a;
//    }
//};

int main()
{
    std::string fun = "x^2+y^2";
    AlgorithmTest algTest( fun);
    algTest.runTests();


//    B b;
//
//    A a(b.zwrocA());
//
//    std::cout << *a.i;

    return 0;
}
