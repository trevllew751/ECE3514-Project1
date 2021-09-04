#include "Matrix.hpp"
#include <climits>

void Matrix::output(std::ostream &out) const {
    for (int i = 0; i < A.size(); i++)
        out << A[i] << " ";

    return;
}

Matrix::Matrix() {
    m = 2;  // num rows
    n = 2;  // num col
    A.assign(m * n, 0);
}

Matrix::Matrix(const std::vector<int> &A, unsigned int n) {
    if (n == 0 || A.size() % n != 0) {
        this->m = 0;
        this->n = 0;
    } else {
        this->m = A.size() / n;
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->A.push_back(A.at((i * m) + j));
            }
        }
    }
}

Matrix::Matrix(const std::vector<int> &A, unsigned int m, unsigned int n) {
    if ((m * n) != A.size()) {
        this->m = 0;
        this->n = 0;
    } else {
        this->m = m;
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->A.push_back(A.at((i * m) + j));
            }
        }
    }
}

int Matrix::get(unsigned int i) const {
    if (i < A.size()) {
        return A.at(i);
    }
    return INT_MIN;
}

int Matrix::get(unsigned int i, unsigned int j) const {
    if (i < m && j < n) {
        return A.at(i + (j * m));
    }
    return INT_MIN;
}

bool Matrix::set(unsigned int i, int ai) {
    if (i < A.size()) {
        A.at(i) = ai;
        return true;
    }
    return false;
}

bool Matrix::set(unsigned int i, unsigned int j, int aij) {
    if (i < m && j < n) {
        A.at(i + (j * m)) = aij;
        return true;
    }
    return false;
}

unsigned int Matrix::size(unsigned int dim) const {
    if (dim == 1) {
        return m;
    }
    if (dim == 2) {
        return n;
    }
    return 0;
}

bool Matrix::equal(const Matrix &rhs) const {
    if (rhs.n != this->n || rhs.m != this->m) {
        return false;
    }
    for (int i = 0; i < A.size(); i++) {
        if (A.at(i) != rhs.A.at(i)) {
            return false;
        }
    }
    return true;
}

const Matrix Matrix::add(const Matrix &rhs) const {
    if (rhs.m != this->m || rhs.n != this->n) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    std::vector<int> vect(A);
    for (int i = 0; i < A.size(); i++) {
        vect.at(i) += rhs.A.at(i);
    }
    return Matrix(vect, this->m, this->n);
}

const Matrix Matrix::sub(const Matrix &rhs) const {
    if (rhs.m != this->m || rhs.n != this->n) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    std::vector<int> vect(A);
    for (int i = 0; i < A.size(); i++) {
        vect.at(i) -= rhs.A.at(i);
    }
    return Matrix(vect, this->m, this->n);
}

const Matrix Matrix::mult(const Matrix &rhs) const {
    if (this->n != rhs.m) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    Matrix result(std::vector<int>(this->m * rhs.n, 0), this->m, rhs.n);
    Matrix matrix(A, m, n);
    int val = 0;
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < rhs.n; j++) {
            for (int k = 0; k < rhs.m; k++) {
                val += rhs.get(k, j) * matrix.get(i, k);
            }
            result.set(i, j, val);
            val = 0;
        }
    }
    return result;
}

const Matrix Matrix::mult(int c) const {
    std::vector<int> vec(A);
    for (int &i : vec) {
        i *= c;
    }
    return Matrix(vec, this->m, this->n);
}

const Matrix Matrix::pow(unsigned int n) const {
    if (this->n != this->m) {
        return Matrix(std::vector<int>(), 0, 0);
    }
    if (n == 0) {
        Matrix result(std::vector<int>(this->m * this->n, 0), this->m, this->n);
        for (int i = 0; i < this->n; i++) {
            result.set(i, i, 1);
        }
        return result;
    }
    Matrix matrix(A, this->m, this->n);
    Matrix result(A, this->m, this->n);
    for (int i = 0; i < n - 1; i++) {
        result = result.mult(matrix);
    }
    return result;
}

const Matrix Matrix::trans() const {
    std::vector<int> vect(this->m * this->n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vect.at(i + (j * n)) = A.at(j + (i * m));
        }
    }
    return Matrix(vect, this->n, this->m);
}
