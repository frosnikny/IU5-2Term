// MyExecRefsLib.cpp
#include <iostream>
#include "../library_lab01/library.h"

using namespace std;

int main() {
    double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
         MathFuncs::MyMathFuncs::Add(a, b) << endl;
    cout << "a - b = " <<
         MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
    cout << "a / b = " <<
         MathFuncs::MyMathFuncs::Division(a, b) << endl;
    cout << "a * b = " <<
         MathFuncs::MyMathFuncs::Multiplication(a, b) << endl;
    return 0;
}
