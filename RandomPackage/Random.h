//
// Created by wenshao on 17-9-27.
//
#include "Matrix.cpp"
#include "Complex.cpp"

#ifndef RANDOMPACKAGE_RANDOM_H
#define RANDOMPACKAGE_RANDOM_H

template<typename T>
class Random {
public:
    Random();

public:
    Matrix<T> randint(int low, int high, int MatrixRow, int MatrixCol);

    T randint(int low, int high);

    Matrix<T> random(int MatrixRow, int MatrixCol);

    T random();

    Matrix<T> uniform(int low, int high, int MatrixRow, int MatrixCol);

    T uniform(int low, int high);

    Matrix<T> choice(const Matrix<T> &obj);

    Matrix<T> shuffle(const Matrix<T> &obj);

//    Matrix<T> expovariate(double lamda, int MatrixRow = 1, int MatrixCol = 1);

    Matrix<T> gauss(int MatrixRow, int MatrixCol, double mu = 0, double sigma = 1.0);

    T gauss(double mu = 0, double sigma = 1.0);

};


#endif //RANDOMPACKAGE_RANDOM_H
