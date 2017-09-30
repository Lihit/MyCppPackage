//
// Created by wenshao on 17-9-27.
//

#include <iostream>

using namespace std;
#ifndef COMPLEXPACKAGE_COMPLEX_H
#define COMPLEXPACKAGE_COMPLEX_H

template<typename T>
class Complex {
    friend ostream &operator<<(ostream &out, Complex &obj) {
        if (obj.imag() > 0) {
            out << obj.real() << "+" << obj.imag() << "*j" << endl;
        } else {
            out << obj.real() << obj.imag() << "*j" << endl;
        }
        return out;
    }

private:
    T Creal;
    T Cimag;
public:
    Complex();

    Complex(T real, T imag);

    Complex(const Complex &obj);

public:
    T real() const;

    T imag() const;

    void setReal(T real);

    void setImag(T imag);

    Complex &conj();

    T modulus();

public:
    Complex operator=(const Complex &obj);

    Complex operator*(const Complex &obj);

    Complex operator-(const Complex &obj);

    Complex operator+(const Complex &obj);

    Complex operator/(const Complex &obj);

    Complex operator*=(const Complex &obj);

    Complex operator^(double power);

};


#endif //COMPLEXPACKAGE_COMPLEX_H
