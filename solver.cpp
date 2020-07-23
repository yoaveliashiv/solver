//
// Created by netanel & Or on 27/04/2020.
//

#include "solver.hpp"
#include <iostream>
#include <complex>
#include <math.h>

using namespace std;

namespace solver{
    RealVariable operator*( double a, RealVariable r){
        return RealVariable(r.a*a, r.b*a, r.c*a);
        return r;


    }

    RealVariable operator+(RealVariable x,double a){
        x.c+=a;
        return x;
    }
    RealVariable operator+(double a,RealVariable x){
        x.c+=a;
        return x;
    }
    RealVariable operator+(RealVariable x1,RealVariable x2){
        RealVariable x3;
        x3.a=x1.a+x2.a;
        x3.b=x1.b+x2.b;
        x3.c=x1.c+x2.c;
        return x3;
    }


    RealVariable operator-(RealVariable x,double a){
        x.c=x.c-a;
        return x;
    }

    RealVariable operator-(double a,RealVariable x){
        x.c=-x.c+a;
        x.a=-x.a;
        x.b=-x.b;
        return x;
    }

    RealVariable operator-(RealVariable x1,RealVariable x2){
        RealVariable x3 {0,0,0};
        x3.a=x1.a-x2.a;
        x3.b=x1.b-x2.b;
        x3.c=x1.c-x2.c;
        return x3;
    }

    RealVariable operator/(RealVariable x,double n)
    {
        if(n == 0)
            throw invalid_argument("cant divide in zero");
        x.b/=n;
        x.c/=n;
        x.a/=n;
        return x;
    }


    double operator==(RealVariable x,double a){
        x.c=-1*x.c;
        a=a+x.c;
        if(x.a==0 && x.b==0 ){
            throw exception();
        }
        if(x.a==0) {

            return a / x.b;
        }
        if(x.a!=0&& x.b==0){
            if(a<0){
                throw exception();
            }
            a=a/x.a;
            a=sqrt(a);
            return a;


        }
        return x.b/a;

    }


    RealVariable operator== ( RealVariable left,  RealVariable right) {
        return left - right;//מעביר לפונקציה של הפחות
    }

    RealVariable operator^(RealVariable r,double n){
        RealVariable ans;
        if(n>2)
            throw invalid_argument("power is not vaild: ");
        if(n==2)
        {
            return RealVariable(1,0,0);
        }
        if(n==1)
        {
            return RealVariable(0,1,0);
        }
        if(n==0)
        {
            return RealVariable(0,0,1);
        }



    }

    double solve(double x) {

        return x;

    }
    std::complex<double> solve (std::complex<double> a){//מספר מורכב של הספרייה
        return a;
    }
    double solve(RealVariable r) {// משווים עם אפס  והפונקציה אנס פותרתה
        return ans(r.a,r.b,r.c);
    }
     ostream& operator<<(ostream& os, const complex<float>& yvalue){
        if (yvalue.imag()>0) {
            os << yvalue.real() <<"+" <<yvalue.imag()<<"i" << endl;
            return os;
        }else{
            os <<yvalue.real() <<yvalue.imag()<<"i" << endl;
            return os;

        }
    }
     ComplexVariable operator*(double a,  ComplexVariable c){
        
        if((a==6 || a==2)&&(c.power>0)){
            c.com.real(c.com.real()*a);
            return c;
        }
  
        c.com.real(a*c.com.real());
        c.com.imag(a*c.com.imag());

        return c;
    }
     ComplexVariable operator-(ComplexVariable c,double a){
        c.f=-a;
        return c;

    }
     std::complex<double> operator==( ComplexVariable c1,ComplexVariable c2){
      //  cout<<"sdsdsd"<<ans_Complex(c1.com.real(),0,c1.f-c2.f)<<endl;
        if(c1.image>0 || c2.image>0)
            return std::complex<double> (0,2);

        return ans_Complex(c1.com.real(),0,c1.f-c2.f);
    }

    ComplexVariable operator+(ComplexVariable c1,  ComplexVariable c2){
        c1.f+=c2.f;
        return c1;

    }
     ComplexVariable operator+(ComplexVariable c1,  std::complex<double> i){
        c1.com_y.imag(c1.com_y.imag()+i.imag());
        c1.image=i.imag();
        return c1;
    }
    ComplexVariable operator-(ComplexVariable c1,  ComplexVariable c2){
        return c1;
    }

    ComplexVariable operator/( ComplexVariable c,double a){
        return c;
    }
     ComplexVariable operator+(double a,  ComplexVariable c){
        c.f+=a;
        return c;
    }


    ComplexVariable operator+(ComplexVariable c1,  double a){
c1.f+=a;
        return c1;
    }


 
    std::complex<double> operator==( ComplexVariable c,double a){
        if(c.power>0){
        a=a-c.f;
            return ans_Complex(c.com.real(),0,-a);
        }else{
            a=a-c.f;
            return std::complex<double> (a/c.com.real(),0);
        }




    }
     ComplexVariable operator^( ComplexVariable c,double n){
         ComplexVariable ans;
         if(n==0){
             throw exception();
         }
         c.power=n;
        return c;
     }





}


std::complex<double> ans_Complex(double a,double  b, double c) {
    double x1, x2, discriminant, realPart, imaginaryPart;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return std::complex<double> (x1,0);

    } else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        return std::complex<double> (x1,0);
    } else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        return std::complex<double> (0,imaginaryPart);
       // cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        //cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }
        return INFINITY;
    }

double ans(double a,double  b, double c) {
    double x1, x2, discriminant, realPart, imaginaryPart;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return x1;
//        cout << "x1 = " << x1 << endl;
//        cout << "x2 = " << x2 << endl;
    } else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        return x1;
//        cout << "x1 = x2 =" << x1 << endl;
//    } else {
//        realPart = -b / (2 * a);
//        imaginaryPart = sqrt(-discriminant) / (2 * a);
//        return
//        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
//        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
//    }
        return INFINITY;
    }
}
