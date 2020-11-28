
#include "fparser4.5.2/fparser.hh"

#include <iostream>
#include <string>
//#include "TestPoint.h"
#include "FunctionTest.h"

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

    FunctionTest functionTest;
    functionTest.test();
    
    // Mój nowy
    // hej to dodany komentarz filipa
    // <include> cos tam

>>>>>>> 63ba2a67b3936062ad279cb05bc92baad8812619

    return 0;
}
