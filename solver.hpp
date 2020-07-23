//
// Created by netanel and or on 27/04/2020.
//

#include <complex>

#include <iostream>
#ifndef SOLVER_SOLVER_HPP
#define SOLVER_SOLVER_HPP
using namespace std;
namespace solver {
    double solve(double x);

        class RealVariable {//מספר ממשי

        private:
        double a=0, b=0, c=0;//2+3x +x^2 a=1 b=3 c=2

    public:
        RealVariable() : a(0), b(1), c(0) {}//בנאי דיפולטיבי רשימת אתחול

        RealVariable(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;

        }
//const קבוע
       friend ostream &operator<<(ostream &os, const RealVariable &r);// הדפסה_דורסים את הסימון>> וזרם פלט

        friend RealVariable operator+(double a, RealVariable x);

        friend RealVariable operator+(RealVariable x, double a);

        friend RealVariable operator+(RealVariable x1, RealVariable x2);

        friend RealVariable operator*( double a, RealVariable r);

        friend RealVariable operator*(RealVariable x, double a);

        friend RealVariable operator*(RealVariable x1, RealVariable x2);

        friend RealVariable operator-(RealVariable x, double a);

        friend RealVariable operator-(double a, RealVariable x);

        friend RealVariable operator-(RealVariable x1, RealVariable x2);

        friend double operator==(RealVariable x, double a);
        friend  RealVariable operator== ( RealVariable left,  RealVariable right);
//        friend RealVariable operator== (const double n, const RealVariable& right);
//friend RealVariable operator== (const RealVariable& left, const double n);
        friend RealVariable operator^(RealVariable, double n);

        friend RealVariable operator/(RealVariable, double n);

        friend RealVariable operator/(RealVariable x1, RealVariable x2);
          friend  double solve(RealVariable r) ;


    };


    class ComplexVariable{ //מספרים מורכבים
        private:
            int power=0;//(2+3i)^2
            std::complex<double> com;//רק מקדם של איקס עם מספ מורכב
            std::complex<double> com_y;//כולל האיקס
            double f;//המספר חופשי
            int image=0;

        public:
            ComplexVariable() :com(1,1) ,f(0)   {}
            ComplexVariable(double re, double im){
                com.imag(im);
                com.real(re);
            }
             friend  ostream& operator<<(ostream&, const complex<float>&);
            friend ComplexVariable operator*(double a,  ComplexVariable c);
            friend ComplexVariable operator+(ComplexVariable c1,  ComplexVariable c2);
            friend ComplexVariable operator+(ComplexVariable c1,  double i);
            friend ComplexVariable operator+(ComplexVariable c1,  std::complex<double> i);
            friend ComplexVariable operator+(double a,  ComplexVariable c);
            friend ComplexVariable operator/(ComplexVariable c1,  double a);
            friend ComplexVariable operator-( ComplexVariable c,double a);
            friend ComplexVariable operator-( ComplexVariable c1,ComplexVariable c2);
            friend std::complex<double> operator==( ComplexVariable c,double a);
            friend  std::complex<double> operator==( ComplexVariable c1,ComplexVariable c2);
            friend ComplexVariable operator^( ComplexVariable c,double n);

        };
     std::complex<double> solve (std::complex<double> a);




#endif //SOLVER_SOLVER_HPP
}
double ans(double ,double ,double );
std::complex<double> ans_Complex(double a,double  b, double c);
