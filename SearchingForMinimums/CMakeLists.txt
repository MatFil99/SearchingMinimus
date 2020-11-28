cmake_minimum_required(VERSION 3.13)
project(SearchingForMinimums)

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchingForMinimums main.cpp fparser4.5.2/fparser.cc fparser4.5.2/fparser.hh fparser4.5.2/fparser_gmpint.hh fparser4.5.2/fparser_mpfr.hh fparser4.5.2/fpconfig.hh fparser4.5.2/fpoptimizer.cc
        fparser4.5.2/extrasrc/fptypes.hh fparser4.5.2/extrasrc/fpaux.hh Gradient.h Gradient.cpp Point.cpp Point.h MinimumsList.cpp MinimumsList.h VectorN.cpp VectorN.h Function.cpp Function.h TestPoint.cpp TestPoint.h FunctionTest.h Algorithm.cpp Algorithm.h)