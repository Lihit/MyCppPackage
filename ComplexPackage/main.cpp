#include <iostream>
#include "Complex.cpp"

using namespace std;

int main() {
    /*Complex<double> tmp(1, 2);
    cout << tmp;
    Complex<double> tmp1(11, 12);
    Complex<double> tmp2=tmp+tmp1;
    cout<<tmp2;
    cout<<tmp2.conj()<<endl;
    cout<<tmp1.modulus()<<endl;
    return 0;*/
    Complex<double> tmp(-1, -6);
    Complex<double> ret = tmp ^0.5;
    cout << ret;
}