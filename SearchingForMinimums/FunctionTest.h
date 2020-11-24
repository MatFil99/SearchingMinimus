#ifndef SEARCHINGFORMINIMUMS_FUNCTIONTEST_H
#define SEARCHINGFORMINIMUMS_FUNCTIONTEST_H

#include <string>
#include "Function.h"
#include <assert.h>
#include "VectorN.h"
#include <float.h>


class FunctionTest {

public:
    void test() {
        std::string f = "a^2+5*b^3+3*c^3+2*d*sin(e)";
        Function function(f);
        VectorN point(5);
        point.setNVal(0, 1);
        point.setNVal(1, 2);
        point.setNVal(2, -2);
        point.setNVal(3, 1);
        point.setNVal(4, 3.14159265359);

        assert(function.getValue(point) > 16.9 && function.getValue(point) < 17.1);
        VectorN gradient(function.getGradient(point, DBL_MIN));
        VectorN expected(5);
        expected.setNVal(0, 2);
        expected.setNVal(1, 60);
        expected.setNVal(2, 36);
        expected.setNVal(3, 0);
        expected.setNVal(4, 2);

        assert(gradient == expected);

    }

};


#endif //SEARCHINGFORMINIMUMS_FUNCTIONTEST_H
