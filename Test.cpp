//
// Created by netanel & Or  on 28/04/2020.
//

#include "doctest.h"
#include "solver.hpp"
#include <iostream>
using namespace std;

using solver::solve,solver::RealVariable, solver::ComplexVariable;
TEST_CASE("solve"){
    RealVariable x;
    CHECK( solve(2*x-4 == 10)==7);  // 7
    CHECK( solve((x^2) == 16)==4);
   CHECK_THROWS(solve((x^2) == -16));
   CHECK( solve((x^2) + 2*x + 4.0 == 20 + 6.0*x/2 - x)==4);
    double xvalue = solve(2*x-4.0 == 10.0);   // xvalue == 7
    CHECK(xvalue==7);
    for (double i=1; i<100;i++) {
        double  temp=i;
        CHECK(solve(temp*x == i) == 1);
    }

}