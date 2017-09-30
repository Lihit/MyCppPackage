//
// Created by wenshao on 17-9-22.
//
#include <iostream>

using namespace std;

#ifndef MATRIXPACKAGE_MATRIX_H
#define MATRIXPACKAGE_MATRIX_H

template<typename T>
class Matrix {
    friend ostream &operator<<(ostream &out, Matrix &mat) {
        for (int i = 0; i < mat.row(); i++) {
            for (int j = 0; j < mat.col(); j++) {
                out << mat(i, j) << " ";
            }
            out << endl;
        }
        out << endl;
        return out;
    }

public:
    Matrix();

    Matrix(T *Array, int ArrayRow, int ArrayCol);

    Matrix(T **Array, int ArrayRow, int ArrayCol);

    Matrix(int MatrixRow, int MatrixCol, T val);

    Matrix(const Matrix &mat);

public:
    ~Matrix();

public:
    T &operator()(int i, int j) const;

    Matrix &operator=(const Matrix &mat);

    Matrix operator+(Matrix &mat);

    Matrix operator+(double AddNum);

    Matrix operator-(Matrix &mat);

    Matrix operator-(double SubNum);

    Matrix operator*(Matrix &mat);

    Matrix operator*(double MultiplyNum);

    Matrix operator*=(Matrix &mat);

    Matrix operator/(Matrix &mat);

    Matrix operator/(double DivNum);

    bool operator==(Matrix &mat);

    bool operator!=(Matrix &mat);

    Matrix operator^(double power);

public:
    void print();

    int *size() const;

    int lenght() const;

    int row() const;

    Matrix &resize(int MatrixRow_new, int MatrixCol_new);

    Matrix &swap(int swapIndex1, int swapIndex2, int axis);

    void setrow(int MatrixRow);

    int col() const;

    void setcol(int MatrixCol);

    void setMat(int index_i, int index_j, T value);

    void setMat(int MatLen, int value);

    T *getArray(int *ArrayLen);

    Matrix &transpose();

    Matrix inv();

    int rank() const;

    double det() const;

    void MultiplyRow(int rowIndex, double multiplyValue);

    void AddRows(int rowIndex_to, int rowIndex_from, double multiplyValue);

    Matrix &negative();

    Matrix &zeros(int MatrixRow, int MatrixCol);

    Matrix &ones(int MatrixRow, int MatrixCol);

    Matrix &eyes(int MatrixLen);

    Matrix &range(T low, T high, int len);

    Matrix &diagonal(T *Array, int ArrayLen);

    Matrix slice(int i_low, int i_high, int j_low, int j_high) const;

    Matrix sliceByIndex(Matrix &MatrixRowIndex, Matrix &MatrixColIndex) const;

    Matrix sliceByIndex(Matrix &MatrixIndex, int axis = 0) const;

    T max();

    Matrix max(int axis);

    T min();

    Matrix min(int axis);

    T sum();

    Matrix sum(int axis);

    T mean();

    Matrix mean(int axis);

    Matrix flatten();

    Matrix &sort(int index = 0, int axis = 1, int SortMode = 0);

private:
    int MatrixRow;
    int MatrixCol;
    T *Mat;
};


#endif //MATRIXPACKAGE_MATRIX_H
