//
// Created by wenshao on 17-9-22.
//

#include "Matrix.h"
#include <cstring>
#include <cmath>

/*
 *  int MatrixRow;
 *  int MatrixCol
 *  T *Mat;
 */
template<typename T>
Matrix<T>::Matrix() {
    this->MatrixRow = 0;
    this->MatrixCol = 0;
    this->Mat = NULL;
}

template<typename T>
Matrix<T>::Matrix(T *Array, int ArrayRow, int ArrayCol) {
    if (Array == NULL) {
        MatrixRow = 0;
        MatrixCol = 0;
        Mat = NULL;
    }
    this->MatrixRow = ArrayRow;
    this->MatrixCol = ArrayCol;
    int MatrixLen = MatrixRow * MatrixCol;
    Mat = new T[MatrixLen];
    for (int i = 0; i < MatrixLen; i++) {
        this->Mat[i] = Array[i];
    }
}

template<typename T>
Matrix<T>::Matrix(T **Array, int ArrayRow, int ArrayCol) {
    if (Array == NULL) {
        MatrixRow = 0;
        MatrixCol = 0;
        Mat = NULL;
    }
    this->MatrixRow = ArrayRow;
    this->MatrixCol = ArrayCol;
    int MatrixLen = MatrixRow * MatrixCol;
    this->Mat = new T[MatrixLen];
    for (int i = 0; i < ArrayRow; i++) {
        for (int j = 0; j < ArrayCol; j++) {
            this->Mat[i * ArrayCol + j] = Array[i][j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(int MatrixRow, int MatrixCol, T val) {
    this->MatrixRow = MatrixRow;
    this->MatrixCol = MatrixCol;
    int MatrixLen = MatrixRow * MatrixCol;
    this->Mat = new T[MatrixLen];
    for (int i = 0; i < MatrixLen; i++) {
        this->Mat[i] = val;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &mat) {
    int rowlen = mat.row();
    int collen = mat.col();
    this->MatrixRow = rowlen;
    this->MatrixCol = collen;
    this->Mat = new T[rowlen * collen];
    for (int i = 0; i < rowlen; i++) {
        for (int j = 0; j < collen; j++) {
            this->Mat[i * collen + j] = mat(i, j);
        }
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    if (Mat != NULL) {
        delete[] Mat;
        Mat = NULL;
    }
    MatrixRow = 0;
    MatrixCol = 0;
}

template<typename T>
T &Matrix<T>::operator()(int i, int j) const {
    return this->Mat[this->MatrixCol * i + j];
}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &mat) {
    if (this->Mat != NULL) {
        this->Mat = NULL;
        this->MatrixCol = 0;
        this->MatrixRow = 0;
    }
    this->MatrixCol = mat.col();
    this->MatrixRow = mat.row();
    this->Mat = new T[mat.row() * mat.col()];
    for (int i = 0; i < this->MatrixRow; i++) {
        for (int j = 0; j < this->MatrixCol; j++) {
            this->Mat[this->MatrixCol * i + j] = mat(i, j);
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> ret;
        return ret;
    } else {
        Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < this->MatrixCol; j++) {
                ret.setMat(i, j, (*this)(i, j) + mat(i, j));
            }
        }
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> ret;
        return ret;
    } else {
        Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < this->MatrixCol; j++) {
                ret.setMat(i, j, (*this)(i, j) - mat(i, j));
            }
        }
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &mat) {
    if (this->MatrixCol != mat.row()) {
        Matrix<T> ret;
        return ret;
    } else {
        Matrix<T> ret(this->MatrixRow, mat.col(), 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < mat.col(); j++) {
                T tmp = 0;
                for (int k = 0; k < this->MatrixCol; k++) {
                    tmp += (*this)(i, k) * mat(k, j);
                }
                ret.setMat(i, j, tmp);
            }
        }
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> ret;
        return ret;
    } else {
        Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < this->MatrixCol; j++) {
                ret.setMat(i, j, (*this)(i, j) * mat(i, j));
            }
        }
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator/(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> ret;
        return ret;
    } else {
        Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < this->MatrixCol; j++) {
                ret.setMat(i, j, (*this)(i, j) / mat(i, j));
            }
        }
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(double AddNum) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; i++) {
        for (int j = 0; j < this->MatrixCol; j++) {
            ret.setMat(i, j, (*this)(i, j) + AddNum);
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(double MultiplyNum) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; i++) {
        for (int j = 0; j < this->MatrixCol; j++) {
            ret.setMat(i, j, (*this)(i, j) * MultiplyNum);
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(double DivNum) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; i++) {
        for (int j = 0; j < this->MatrixCol; j++) {
            ret.setMat(i, j, (*this)(i, j) / DivNum);
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(double SubNum) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; i++) {
        for (int j = 0; j < this->MatrixCol; j++) {
            ret.setMat(i, j, (*this)(i, j) - SubNum);
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator==(Matrix<T> &mat) {
    if (this->MatrixCol == mat.row() && this->MatrixRow == mat.col()) {
        Matrix<T> ret(mat.row(), mat.col(), 0);
        for (int i = 0; i < this->MatrixRow; i++) {
            for (int j = 0; j < this->MatrixCol; j++) {
                if ((*this)(i, j) == mat(i, j)) {
                    ret(i, j) = 0;
                }
            }
        }
        return ret;
    } else {
        Matrix<T> tmp;
        return tmp;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator!=(Matrix<T> &mat) {
    return ~(*this == mat);
}

template<typename T>
Matrix<T> Matrix<T>::operator^(double power) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 1);
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            ret(i, j) = pow((*this)(i, j), power);
        }
    }
    return ret;
}

template<typename T>
Matrix<T> &Matrix<T>::transpose() {
    if (this->Mat != NULL) {
        int rowlen = this->MatrixRow;
        int collen = this->MatrixCol;
        this->MatrixCol = rowlen;
        this->MatrixRow = collen;
        T *tmp = new T[rowlen * collen];
        for (int i = 0; i < rowlen; ++i) {
            for (int j = 0; j < collen; ++j) {
                tmp[j * rowlen + i] = (*this)(i, j);
            }
        }
        delete[] this->Mat;
        this->Mat = tmp;
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::inv() {
    if (this->MatrixRow != this->MatrixCol) {
        Matrix<T> ret;
        return ret;
    }
    Matrix<T> tmp = *this;
    Matrix<T> MatEyes;
    MatEyes.eyes(this->MatrixRow);
    for (int i = 0; i < tmp.row(); ++i) {
        if (tmp(i, i) == 0) {
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    tmp.swap(i, j, 0);
                    MatEyes.swap(i, j, 0);
                    break;
                }
            }
        }
        if (tmp(i, i) == 0) {
            Matrix<T> ret;
            return ret;
        } else {
            T value_tmp1 = 1.0 / tmp(i, i);
            tmp.MultiplyRow(i, value_tmp1);
            MatEyes.MultiplyRow(i, value_tmp1);
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    T value_tmp2 = -1.0 * tmp(j, i) / tmp(i, i);
                    tmp.AddRows(j, i, value_tmp2);
                    MatEyes.AddRows(j, i, value_tmp2);
                }
            }
        }
    }
    for (int i = tmp.row() - 1; i >= 0; --i) {
        if (tmp(i, i) == 0) {
            Matrix<T> ret;
            return ret;
        } else {
            for (int j = i - 1; j >= 0; --j) {
                if (tmp(j, i) != 0) {
                    T value_tmp2 = -1.0 * tmp(j, i) / tmp(i, i);
                    tmp.AddRows(j, i, value_tmp2);
                    MatEyes.AddRows(j, i, value_tmp2);
                }
            }
        }
    }
    return MatEyes;
}

template<typename T>
int Matrix<T>::rank() const {
    if (this->MatrixRow != this->MatrixCol) {
        return INT32_MAX;
    }
    Matrix<T> tmp = *this;
    for (int i = 0; i < tmp.row(); ++i) {
        if (tmp(i, i) == 0) {
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    tmp.swap(i, j, 0);
                    break;
                }
            }
        }
        if (tmp(i, i) == 0) {
            continue;
        } else {
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    double multiplyValue = -1.0 * tmp(j, i) / tmp(i, i);
                    tmp.AddRows(j, i, multiplyValue);
                }
            }
        }
    }
    int ret = 0;
    for (int k = 0; k < tmp.row(); ++k) {
        if (tmp(k, k)) {
            ret++;
        }
    }
    return ret;
}

template<typename T>
double Matrix<T>::det() const {
    if (this->MatrixRow != this->MatrixCol) {
        return INT32_MAX;
    }
    Matrix<T> tmp = *this;
    for (int i = 0; i < tmp.row(); ++i) {
        if (tmp(i, i) == 0) {
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    tmp.swap(i, j, 0);
                    break;
                }
            }
        }
        if (tmp(i, i) == 0) {
            return 0;
        } else {
            for (int j = i + 1; j < tmp.row(); ++j) {
                if (tmp(j, i) != 0) {
                    double multiplyValue = -1.0 * tmp(j, i) / tmp(i, i);
                    tmp.AddRows(j, i, multiplyValue);
                }
            }
        }
    }
    double ret = 1;
    for (int k = 0; k < tmp.row(); ++k) {
        ret *= tmp(k, k);
    }
    return ret;
}

template<typename T>
Matrix<T> &Matrix<T>::swap(int swapIndex1, int swapIndex2, int axis) {
    if (axis == 0) {
        for (int i = 0; i < this->MatrixCol; ++i) {
            T tmp = (*this)(swapIndex1, i);
            (*this)(swapIndex1, i) = (*this)(swapIndex2, i);
            (*this)(swapIndex2, i) = tmp;
        }
    } else {
        for (int i = 0; i < this->MatrixRow; ++i) {
            T tmp = (*this)(i, swapIndex1);
            (*this)(i, swapIndex1) = (*this)(i, swapIndex2);
            (*this)(i, swapIndex2) = tmp;
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::negative() {
    if (this->Mat != NULL) {
        for (int i = 0; i < this->MatrixRow; ++i) {
            for (int j = 0; j < this->MatrixCol; ++j) {
                (*this)(i, j) = -(*this)(i, j);
            }
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::zeros(int MatrixRow, int MatrixCol) {
    this->setMat(MatrixRow * MatrixCol, 0);
    this->setrow(MatrixRow);
    this->setcol(MatrixCol);
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::ones(int MatrixRow, int MatrixCol) {
    this->setMat(MatrixRow * MatrixCol, 1);
    this->setrow(MatrixRow);
    this->setcol(MatrixCol);
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::eyes(int MatrixLen) {
    if (this->Mat != NULL) {
        delete[] this->Mat;
        this->Mat = NULL;
    }
    this->MatrixCol = MatrixLen;
    this->MatrixRow = MatrixLen;
    this->Mat = new T[MatrixLen * MatrixLen];
    for (int i = 0; i < MatrixLen * MatrixLen; i++) {
        if (i % (MatrixLen + 1) == 0) {
            this->Mat[i] = 1;
        } else {
            this->Mat[i] = 0;
        }

    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::diagonal(T *Array, int ArrayLen) {
    if (this->Mat != NULL) {
        delete[] this->Mat;
        this->Mat = NULL;
    }
    this->MatrixCol = ArrayLen;
    this->MatrixRow = ArrayLen;
    this->Mat = new T[ArrayLen * ArrayLen];
    for (int i = 0; i < ArrayLen * ArrayLen; i++) {
        if (i % (ArrayLen + 1) == 0) {
            this->Mat[i] = Array[i / (ArrayLen + 1)];
        } else {
            this->Mat[i] = 0;
        }

    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::slice(int i_low, int i_high, int j_low, int j_high) const {
    if (i_low < i_high && j_low < j_high) {
        Matrix<T> ret(i_high - i_low, j_high - j_low, 0);
        for (int i = i_low; i < i_high; i++) {
            for (int j = j_low; j < j_high; j++) {
                ret(i - i_low, j - j_low) = (*this)(i, j);
            }
        }
        return ret;
    } else {
        Matrix<T> ret;
        return ret;
    }
}

template<typename T>
Matrix<T> Matrix<T>::sliceByIndex(Matrix<T> &MatrixRowIndex, Matrix<T> &MatrixColIndex) const {
    Matrix<T> ret(MatrixRowIndex.col(), MatrixColIndex.col(), 0);
    for (int i = 0; i < MatrixRowIndex.col(); ++i) {
        for (int j = 0; j < MatrixColIndex.col(); ++j) {
            ret(i, j) = (*this)(MatrixRowIndex(0, i), MatrixColIndex(0, j));
        }
    }
    return ret;
}

template<typename T>
int *Matrix<T>::size() const {
    int *size = new int[2];
    size[0] = this->MatrixRow;
    size[1] = this->MatrixCol;
    return size;
}

template<typename T>
int Matrix<T>::lenght() const {
    return this->MatrixCol * this->MatrixRow;
}

template<typename T>
int Matrix<T>::row() const {
    return this->MatrixRow;
}

template<typename T>
int Matrix<T>::col() const {
    return this->MatrixCol;
}

template<typename T>
void Matrix<T>::setrow(int MatrixRow) {
    this->MatrixRow = MatrixRow;
}

template<typename T>
void Matrix<T>::setcol(int MatrixCol) {
    this->MatrixCol = MatrixCol;
}

template<typename T>
void Matrix<T>::setMat(int MatLen, int value) {
    if (this->Mat != NULL) {
        delete[] this->Mat;
        this->Mat = NULL;
    }
    this->Mat = new T[MatLen];
    for (int i = 0; i < MatLen; i++) {
        this->Mat[i] = value;
    }
}


template<typename T>
void Matrix<T>::AddRows(int rowIndex_to, int rowIndex_from, double multiplyValue) {
    for (int i = 0; i < this->MatrixCol; ++i) {
        (*this)(rowIndex_to, i) += (multiplyValue * (*this)(rowIndex_from, i));
    }
}

template<typename T>
void Matrix<T>::MultiplyRow(int rowIndex, double multiplyValue) {
    for (int i = 0; i < this->MatrixCol; ++i) {
        (*this)(rowIndex, i) *= multiplyValue;
    }
}

template<typename T>
void Matrix<T>::print() {
    for (int i = 0; i < this->row(); i++) {
        for (int j = 0; j < this->col(); j++) {
            cout << (*this)(i, j) << " ";
        }
        cout << endl;
    }
}

template<typename T>
void Matrix<T>::setMat(int index_i, int index_j, T value) {
    this->Mat[this->MatrixCol * index_i + index_j] = value;
}

template<typename T>
Matrix<T> &Matrix<T>::resize(int MatrixRow_new, int MatrixCol_new) {
    if (this->lenght() == MatrixRow_new * MatrixCol_new) {
        this->MatrixRow = MatrixRow_new;
        this->MatrixCol = MatrixCol_new;
    }
    return *this;
}

template<typename T>
T *Matrix<T>::getArray(int *ArrayLen) {
    *ArrayLen = this->lenght();
    T *ret = new T[ArrayLen];
    memcpy(ret, this->Mat, *ArrayLen * sizeof(T));
    return ret;
}

template<typename T>
T Matrix<T>::max() {
    if (this->Mat == NULL) {
        return INT32_MAX;
    }
    T ret = this->Mat[0];
    for (int i = 1; i < this->lenght(); ++i) {
        if (Mat[i] > ret) {
            ret = Mat[i];
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::max(int axis) {
    if (axis == 0) {
        Matrix<T> ret(1, this->MatrixRow, 0);
        for (int i = 0; i < this->MatrixRow; ++i) {
            Matrix<T> tmp = this->slice(i, i + 1, 0, this->MatrixCol);
            ret(0, i) = tmp.max();
        }
        return ret;
    } else {
        Matrix<T> ret(1, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixCol; ++i) {
            Matrix<T> tmp = this->slice(0, this->MatrixRow, i, i + 1);
            ret(0, i) = tmp.max();
        }
        return ret;
    }
}

template<typename T>
T Matrix<T>::min() {
    if (this->Mat == NULL) {
        return INT32_MAX;
    }
    T ret = this->Mat[0];
    for (int i = 1; i < this->lenght(); ++i) {
        if (Mat[i] < ret) {
            ret = Mat[i];
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::min(int axis) {
    if (axis == 0) {
        Matrix<T> ret(1, this->MatrixRow, 0);
        for (int i = 0; i < this->MatrixRow; ++i) {
            Matrix<T> tmp = this->slice(i, i + 1, 0, this->MatrixCol);
            ret(0, i) = tmp.min();
        }
        return ret;
    } else {
        Matrix<T> ret(1, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixCol; ++i) {
            Matrix<T> tmp = this->slice(0, this->MatrixRow, i, i + 1);
            ret(0, i) = tmp.min();
        }
        return ret;
    }
}

template<typename T>
T Matrix<T>::sum() {
    if (this->Mat == NULL) {
        return INT32_MAX;
    }
    T ret = 0;
    for (int i = 0; i < this->lenght(); ++i) {
        ret += this->Mat[i];
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::sum(int axis) {
    if (axis == 0) {
        Matrix<T> ret(1, this->MatrixRow, 0);
        for (int i = 0; i < this->MatrixRow; ++i) {
            Matrix<T> tmp = this->slice(i, i + 1, 0, this->MatrixCol);
            ret(0, i) = tmp.sum();
        }
        return ret;
    } else {
        Matrix<T> ret(1, this->MatrixCol, 0);
        for (int i = 0; i < this->MatrixCol; ++i) {
            Matrix<T> tmp = this->slice(0, this->MatrixRow, i, i + 1);
            ret(0, i) = tmp.sum();
        }
        return ret;
    }
}

template<typename T>
T Matrix<T>::mean() {
    return this->sum() / this->lenght();
}

template<typename T>
Matrix<T> Matrix<T>::mean(int axis) {
    int NumSum = axis == 0 ? this->MatrixRow : this->MatrixCol;
    Matrix<T> ret = this->sum(axis);
    ret.MultiplyRow(0, 1.0 / NumSum);
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::flatten() {
    Matrix<T> ret(1, this->lenght(), 0);
    for (int i = 0; i < this->lenght(); ++i) {
        ret(0, i) = this->Mat[i];
    }
    return ret;
}


template<typename T>
Matrix<T> &Matrix<T>::sort(int index, int axis, int SortMode) {
    if (axis == 0) {
        for (int i = 0; i < this->MatrixCol - 1; ++i) {
            for (int j = i + 1; j < this->MatrixCol; ++j) {
                if (SortMode == 0) {
                    if ((*this)(index, j) < (*this)(index, i)) {
                        this->swap(i, j, 1);
                    }
                } else {
                    if ((*this)(index, j) > (*this)(index, i)) {
                        this->swap(i, j, 1);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < this->MatrixRow - 1; ++i) {
            for (int j = i + 1; j < this->MatrixRow; ++j) {
                if (SortMode == 0) {
                    if ((*this)(j, index) < (*this)(i, index)) {
                        this->swap(i, j, 0);
                    }
                } else {
                    if ((*this)(j, index) > (*this)(i, index)) {
                        this->swap(i, j, 0);
                    }
                }
            }
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::range(T low, T high, int len) {
    if (this->Mat != NULL) {
        delete[] this->Mat;
        this->Mat = NULL;
    }
    this->MatrixCol = len;
    this->MatrixRow = 1;
    this->Mat = new T[len];
    T tmp = (high - low) / len;
    for (int i = 0; i < len; i++) {
        this->Mat[i] = low + i * tmp;
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::sliceByIndex(Matrix<T> &MatrixIndex, int axis) const {
    if (axis == 0) {
        Matrix<T> ColIndex;
        ColIndex.range(0, this->MatrixCol, this->MatrixCol);
        return sliceByIndex(MatrixIndex, ColIndex);
    } else {
        Matrix<T> RowIndex;
        RowIndex.range(0, this->MatrixRow, this->MatrixRow);
        return sliceByIndex(RowIndex, MatrixIndex);
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator>(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> tmp;
        return tmp;
    }
    Matrix<T> ret(mat.row(), mat.col(), 0);
    for (int i = 0; i < mat.row(); ++i) {
        for (int j = 0; j < mat.col(); ++j) {
            if ((*this)(i, j) > mat(i, j)) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator|(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> tmp;
        return tmp;
    }
    Matrix<T> ret(mat.row(), mat.col(), 1);
    for (int i = 0; i < mat.row(); ++i) {
        for (int j = 0; j < mat.col(); ++j) {
            if ((*this)(i, j) == 0 && mat(i, j) == 0) {
                ret(i, j) = 0;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator<(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> tmp;
        return tmp;
    }
    Matrix<T> ret(mat.row(), mat.col(), 0);
    for (int i = 0; i < mat.row(); ++i) {
        for (int j = 0; j < mat.col(); ++j) {
            if ((*this)(i, j) < mat(i, j)) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator&(Matrix<T> &mat) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> tmp;
        return tmp;
    }
    Matrix<T> ret(mat.row(), mat.col(), 0);
    for (int i = 0; i < mat.row(); ++i) {
        for (int j = 0; j < mat.col(); ++j) {
            if ((*this)(i, j) != 0 && mat(i, j) != 0) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}


template<typename T>
Matrix<T> &Matrix<T>::operator~() {
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) == 0) {
                (*this)(i, j) = 1;
            } else {
                (*this)(i, j) = 0;
            }
        }
    }
    return *this;
}

template<typename T>
bool Matrix<T>::haveZero() {
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) == 0) {
                return true;
            }
        }
    }
    return false;
}

template<typename T>
Matrix<T> &Matrix<T>::setVal(Matrix<T> mat, T newVal) {
    if (this->MatrixRow != mat.row() || this->MatrixCol != mat.col()) {
        Matrix<T> tmp;
        return tmp;
    }
    for (int i = 0; i < mat.row(); ++i) {
        for (int j = 0; j < mat.col(); ++j) {
            if (mat(i, j) != 0) {
                (*this)(i, j) = newVal;
            }
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator>(T val) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) > val) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator<(T val) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) < val) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator==(T val) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) == val) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> Matrix<T>::operator!=(T val) {
    Matrix<T> ret(this->MatrixRow, this->MatrixCol, 0);
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) != val) {
                ret(i, j) = 1;
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> &Matrix<T>::operator()(Matrix<T> &mat) {
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if (mat(i, j) != 0) {
                (*this)(i, j) = INT32_MAX;
            }
        }
    }
    return *this;

}

template<typename T>
Matrix<T> &Matrix<T>::operator=(T newVal) {
    for (int i = 0; i < this->MatrixRow; ++i) {
        for (int j = 0; j < this->MatrixCol; ++j) {
            if ((*this)(i, j) == INT32_MAX) {
                (*this)(i, j) = newVal;
            }
        }
    }
    return *this;
}