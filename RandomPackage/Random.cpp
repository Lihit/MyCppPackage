//
// Created by wenshao on 17-9-27.
//

#include "Random.h"

template<typename T>
Matrix<T> Random<T>::randint(int low, int high, int MatrixRow, int MatrixCol) {
    Matrix<T> ret(MatrixRow, MatrixCol, 0);
    for (int i = 0; i < MatrixRow; ++i) {
        for (int j = 0; j < MatrixCol; ++j) {
            ret(i, j) = rand() % (high - low) + low;
        }
    }
    return ret;

}

template<typename T>
Matrix<T> Random<T>::random(int MatrixRow, int MatrixCol) {
    Matrix<T> ret(MatrixRow, MatrixCol, 0);
    for (int i = 0; i < MatrixRow; ++i) {
        for (int j = 0; j < MatrixCol; ++j) {
            ret(i, j) = rand() / (double) RAND_MAX;
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Random<T>::uniform(int low, int high, int MatrixRow, int MatrixCol) {
    Matrix<T> ret(MatrixRow, MatrixCol, 0);
    for (int i = 0; i < MatrixRow; ++i) {
        for (int j = 0; j < MatrixCol; ++j) {
            ret(i, j) = (high - low) * (rand() / (double) RAND_MAX) + low;
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Random<T>::choice(const Matrix<T> &obj) {
    Matrix<T> choiceIndex = this->randint(0, obj.lenght());
    Matrix<T> ret(1, 1, obj((int) choiceIndex(0, 0) / obj.col(), (int) choiceIndex(0, 0) % obj.col()));
    return ret;
}

template<typename T>
Matrix<T> Random<T>::shuffle(const Matrix<T> &obj) {
    Matrix<T> ret = obj;
    Matrix<T> tmp;
    tmp.range(0, obj.lenght(), obj.lenght());
    for (int i = 0; i < obj.lenght(); ++i) {
        Matrix<T> randIndex = this->randint(0, tmp.lenght());
        int index_tmp = tmp(0, randIndex(0, 0));
        ret(i / obj.col(), i % obj.col()) = obj(index_tmp / obj.col(), index_tmp % obj.col());
        tmp.erase((int) randIndex(0, 0));
    }
    return ret;
}

/*template<typename T>
Matrix<T> Random<T>::expovariate(double lamda, int MatrixRow, int MatrixCol) {
    Matrix<T> tmp(10, 10, 1);
    return tmp;
}*/

template<typename T>
Matrix<T> Random<T>::gauss(int MatrixRow, int MatrixCol, double mu, double sigma) {
    Matrix<T> ret(MatrixRow, MatrixCol, 0);
    const double two_pi = 2.0 * 3.14159265358979323846;
    for (int i = 0; i < MatrixRow; ++i) {
        for (int j = 0; j < MatrixCol; ++j) {
            double u1 = rand() * (1.0 / RAND_MAX);
            double z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u1);
            ret(i, j) = z0 * sigma + mu;
        }
    }
    return ret;
}

template<typename T>
Random<T>::Random() {
    srand((unsigned) time(0));
}

template<typename T>
T Random<T>::randint(int low, int high) {
    return rand() % (high - low) + low;
}

template<typename T>
T Random<T>::random() {
    return rand() / (double) RAND_MAX;
}

template<typename T>
T Random<T>::uniform(int low, int high) {
    return (high - low) * (rand() / (double) RAND_MAX) + low;
}

template<typename T>
T Random<T>::gauss(double mu, double sigma) {
    const double two_pi = 2.0 * 3.14159265358979323846;
    double u1 = rand() * (1.0 / RAND_MAX);
    double z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u1);
    return z0 * sigma + mu;
}


