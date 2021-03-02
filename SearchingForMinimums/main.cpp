#include <iostream>

#include <string>
#include "Algorithm.h"
#include "VectorN.h"
#include "Point.h"

#include "AlgorithmTest.h"

struct UserParameters{
    std::string function;
    int divider;
    int leaving_minimum;
    double precision_optimum;
    double start_beta;
    double acceptable_estimation;
    class VectorN vec;
    int dim_of_vec;
};

UserParameters readUserArguments(int &argc, char* argv[]){
    struct UserParameters uPar;
    std::stringstream arg;


    for( int i=1; i<argc && i<7; ++i ){
        arg << argv[i];
        switch(i) {
            case 1:
                arg >> uPar.function;
                break;
            case 2:
                arg >> uPar.divider;
                break;
            case 3:
                arg >> uPar.leaving_minimum;
                break;
            case 4:
                arg >> uPar.precision_optimum;
                break;
            case 5:
                arg >> uPar.start_beta;
                break;
            case 6:
                arg >> uPar.acceptable_estimation;
        }
        arg.clear();
    }
    uPar.dim_of_vec = std::max(argc - 7, 0);
    double *tab = new double[uPar.dim_of_vec];
    for(int i = 7; i<argc; ++i ){
        arg << argv[i];
        arg >> tab[i-7];
        arg.clear();
    }
    VectorN v(uPar.dim_of_vec, tab);
    uPar.vec=v;
    delete [] tab;
    return uPar;
}

bool correctParameters(int argc, struct UserParameters uPar){
    if(argc<7){ return false; }
    if(uPar.divider==0 || uPar.leaving_minimum==0 || uPar.precision_optimum==0 || uPar.start_beta==0 || uPar.acceptable_estimation==0){
        return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    struct UserParameters uPar=readUserArguments(argc, argv);

    if (correctParameters(argc, uPar)){
        double tab[2] = { 0, 0 };
        double val = 0;
        VectorN v(2, tab);
        Point min(v, val);

        std::cout << "Funkcja: " << uPar.function <<"\n";
        std::cout << "divider " << uPar.divider <<";\t";
        std::cout << "leaving_minimum " << uPar.leaving_minimum <<"\t";
        std::cout << "precision_optimum " << uPar.precision_optimum <<"\t";
        std::cout << "start_beta "<< uPar.start_beta <<"\t";
        std::cout << "acceptable_estimation "<< uPar.acceptable_estimation <<"\t";
        std::cout << "start_point " << uPar.vec <<"\n\n";

        Algorithm algorithm(uPar.function, uPar.divider, uPar.leaving_minimum, uPar.precision_optimum, uPar.start_beta, uPar.acceptable_estimation, uPar.dim_of_vec);
        algorithm.searchAllMinimums(uPar.vec);
        Point min_found = algorithm.getFoundOptimum();
        std::cout << min_found << "\n";
        // std::cout << (min_found.getVectorN()-min.getVectorN()).getNorm() << "\n";
        // std::cout << std::abs(min.getValue-min_found.getValue);
        // std::cout << algorithm.getMinList().getListMin().size();
    }else{
        std::cout << "Wrong parameters\n\n";
        std::cout << "Scheme of call:\n";
        std::cout << "./Search \"function\" divider leaving_minimum precision_optimum start_beta acceptable_estimation start_point\n";

        std::cout << "Example:\n";
        std::cout << "./Search \"20+x^2-10*cos(2*3.14*x)+y^2-10*cos(2*3.14*y)\" 10 400 0.005 0.159 0.001 5 3\n";
    }


    


// -----
    // double *tab = (double*) new double[4];
    // tab[0] = 1; tab[1] = 2; tab[2] = 3; tab[3] = 4;
    // VectorN v(4, tab);
    // std::cout << v;

    // delete [] tab;

    // std::cout << "Liczby: " << liczba1 ;
        // Algorithm a = Algorithm("x^2+y^2", divider, leaving_limit, precision_optimum, start_beta, acceptable_estimation);
        // VectorN start = VectorN(2);
        // start.setNVal(0, x1);
        // start.setNVal(1, x2);
        // a.searchAllMinimums(start);
        // a.getMinList().printList();
        // std::cout << a.getFoundOptimum();
        // std::cout << "Podaj wszystkie parametry algorytmu\n";
    
    // AlgorithmTest algTest;
    // algTest.runTests();

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
