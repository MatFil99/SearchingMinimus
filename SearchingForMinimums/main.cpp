
#include "fparser4.5.2/fparser.hh"

#include <iostream>
#include <string>

int main()
{
    std::string function;
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

    return 0;
}
