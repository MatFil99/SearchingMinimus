
#include "fparser4.5.2/fparser.hh"

#include <iostream>
#include <string>
//#include "TestPoint.h"
#include "FunctionTest.h"

#include "MinimumsList.h"

//Useless comment

int main()
{
    std::string function;
    double minx = 5, maxx = 10;
    int step = 1;

   /* std::string function;
    double minx, maxx, step;
    FunctionParser fparser;

    while(true)
    {
        std::cout << "f = ";
        std::getline(std::cin, function);
        if(std::cin.fail()) return 0;

        int res = fparser.ParseAndDeduceVariables(function);
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparser.ErrorMsg() << "\n\n";
    }

    double vals[] = { 0 };
    for(vals[0] = minx; vals[0] <= maxx; vals[0] += step)
    {
        std::cout << "f(" << vals[0] << ") = " << fparser.Eval(vals)
                  << std::endl;
    }
    */



    /*TestPoint t;
    t.testujPunkt();
    */



    MinimumsList mlist;


    VectorN v(2), v2(2), v3(2), v4(2);

    Point p1(v, 10), p2(v2, 20), p3(v3, 30), p4(v4, 40);

    mlist.addMinimumToList(p1);
    mlist.addMinimumToList(p2);
    mlist.addMinimumToList(p3);
    mlist.addMinimumToList(p4);


    return 0;
}
