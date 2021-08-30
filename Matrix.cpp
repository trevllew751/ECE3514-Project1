#include "Matrix.hpp"

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
    if (n <= 0) {
        m = 0;
        this->n = 0;
    } else {
        m = n;
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->A.push_back(A.at(j));
            }
        }
    }
}

Matrix::Matrix(const std::vector<int> &A, unsigned int m, unsigned int n) {
    if (n <= 0 || m <= 0) {
        this->m = 0;
        this->n = 0;
    } else {
        this->m = m;
        this->n = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->A.push_back(A.at(j));
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
        return n;
    }
    if (dim == 2) {
        return m;
    }
    return 0;
}

bool Matrix::equal(const Matrix &rhs) const {
    if (rhs.A.size() != A.size()) {
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
    return Matrix();
}

const Matrix Matrix::sub(const Matrix &rhs) const {
    return Matrix();
}

const Matrix Matrix::mult(const Matrix &rhs) const {
    return Matrix();
}

const Matrix Matrix::mult(int c) const {
    std::vector<int> vec = A;
    for (int & i : vec) {
        i *= c;
    }
    return Matrix(vec, m, n);
}

const Matrix Matrix::pow(unsigned int n) const {
    return Matrix();
}

const Matrix Matrix::trans(const Matrix &rhs) const {
    return Matrix();
}
