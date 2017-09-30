//
// Created by wenshao on 17-9-27.
//

#include "Complex.h"
#include <cmath>

template<typename T>
Complex<T>::Complex() {
    this->Creal = 0;
    this->Cimag = 0;
}

template<typename T>
Complex<T>::Complex(T real, T imag) {
    this->Creal = real;
    this->Cimag = imag;
}

template<typename T>
Complex<T>::Complex(const Complex<T> &obj) {
    this->Creal = obj.real();
    this->Cimag = obj.imag();
}

template<typename T>
T Complex<T>::real() const {
    return this->Creal;
}

template<typename T>
T Complex<T>::imag() const {
    return this->Cimag;
}

template<typename T>
Complex<T> Complex<T>::operator=(const Complex<T> &obj) {
    this->Creal = obj.real();
    this->Cimag = obj.imag();
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T> &obj) {
    Complex<T> ret;
    ret.setReal(this->real() * obj.real());
    ret.setImag(this->imag() * obj.imag());
    return ret;
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T> &obj) {
    Complex<T> ret;
    ret.setReal(this->real() - obj.real());
    ret.setImag(this->imag() - obj.imag());
    return ret;
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &obj) {
    Complex<T> ret;
    ret.setReal(this->real() + obj.real());
    ret.setImag(this->imag() + obj.imag());
    return ret;
}

template<typename T>
Complex<T> Complex<T>::operator/(const Complex<T> &obj) {
    Complex<T> ret;
    ret.setReal(this->real() / obj.real());
    ret.setImag(this->imag() / obj.imag());
    return ret;
}

template<typename T>
Complex<T> Complex<T>::operator*=(const Complex<T> &obj) {
    Complex<T> ret;
    ret.setReal(this->real() * obj.real() - this->imag() * obj.imag());
    ret.setImag(this->real() * obj.imag() + this->imag() * obj.real());
    return ret;
}

template<typename T>
void Complex<T>::setReal(T real) {
    this->Creal = real;
}

template<typename T>
void Complex<T>::setImag(T imag) {
    this->Cimag = imag;
}

template<typename T>
Complex<T> &Complex<T>::conj() {
    this->Cimag = -this->Cimag;
    return *this;
}

template<typename T>
T Complex<T>::modulus() {
    T sum = pow(this->Creal, 2) + pow(this->Cimag, 2);
    return pow(sum, 0.5);
}
template<typename T>
Complex<T> Complex<T>::operator^(double power) {
    T Treal=this->Creal;
    T Timag=this->Cimag;
    Complex<T> RealCom,ImagCom;
    if(Treal<0){
        RealCom.setImag(pow(abs(Treal),power));
    } else{
        RealCom.setReal(pow(abs(Treal),power));
    }
    if(Timag<0){
        ImagCom.setReal(-pow(abs(Timag),power));
    } else{
        ImagCom.setImag(pow(abs(Treal),power));
    }
    return RealCom+ImagCom;
}


