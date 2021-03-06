#include "catch.hpp"
#include "Matrix.hpp"
#include <climits>

TEST_CASE("default constructor", "[Matrix]")
{
    INFO("Hint: default constructor (linear get() must work)");
    Matrix A;

    REQUIRE(A.get(0) == 0);
    REQUIRE(A.get(1) == 0);
    REQUIRE(A.get(2) == 0);
    REQUIRE(A.get(3) == 0);

    REQUIRE(A.size(1) == 2);
    REQUIRE(A.size(2) == 2);
}

TEST_CASE("parameterized constructor (vector, n)", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    Matrix A(vect, 2);
    REQUIRE(A.get(0) == 1);
    REQUIRE(A.get(1) == 2);
    REQUIRE(A.get(2) == 3);
    REQUIRE(A.get(3) == 4);
    REQUIRE(A.get(4) == 5);
    REQUIRE(A.get(5) == 6);

    std::vector<int> vect1{1, 2, 3};
    Matrix B(vect, 4);
    REQUIRE(B.size(1) == 0);
    REQUIRE(B.size(2) == 0);

    REQUIRE(A.size(1) == 3);
    REQUIRE(A.size(2) == 2);
    REQUIRE(A.get(100) == INT_MIN);
}

TEST_CASE("parameterized constructor (vector, m, n)", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    Matrix A(vect, 3, 2);
    REQUIRE(A.get(0) == 1);
    REQUIRE(A.get(1) == 2);
    REQUIRE(A.get(2) == 3);
    REQUIRE(A.get(3) == 4);
    REQUIRE(A.get(4) == 5);
    REQUIRE(A.get(5) == 6);

    REQUIRE(A.size(1) == 3);
    REQUIRE(A.size(2) == 2);
    REQUIRE(A.get(100) == INT_MIN);
}

TEST_CASE("row and column index get (i, j)", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    Matrix A(vect, 3, 2);
    REQUIRE(A.get(0, 0) == 1);
    REQUIRE(A.get(1, 0) == 2);
    REQUIRE(A.get(2, 0) == 3);
    REQUIRE(A.get(0, 1) == 4);
    REQUIRE(A.get(1, 1) == 5);
    REQUIRE(A.get(2, 1) == 6);

    REQUIRE(A.get(100, 0) == INT_MIN);
    REQUIRE(A.get(0, 10) == INT_MIN);
}

TEST_CASE("linear set (i, ai)", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    Matrix A(vect, 3, 2);
    REQUIRE(A.set(1, 100));
    REQUIRE(A.get(1) == 100);
    REQUIRE(!A.set(100, 10));
}

TEST_CASE("row and column index set(i, j, aij)", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    Matrix A(vect, 3, 2);
    REQUIRE(A.set(1, 1, 100));
    REQUIRE(A.get(1, 1) == 100);
    REQUIRE(!A.set(100, 1, 10));
    REQUIRE(!A.set(1, 100, 10));
}

TEST_CASE("equals method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    std::vector<int> vect1{6, 5, 4, 3, 2, 1};
    std::vector<int> vect2{1, 2, 3, 4, 5, 6, 7, 8};
    Matrix A(vect, 3, 2);
    Matrix B(vect, 3, 2);
    Matrix C;
    Matrix D(vect1, 3, 2);
    Matrix E(vect2, 4, 2);
    REQUIRE(A.equal(B));
    REQUIRE(!A.equal(C));
    REQUIRE(!A.equal(D));
    REQUIRE(!A.equal(E));
}

TEST_CASE("add method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    std::vector<int> vect1{1, 1, 1, 1, 1, 1};
    std::vector<int> vect2{2, 3, 4, 5, 6, 7};
    Matrix A(vect, 3, 2);
    Matrix B(vect1, 3, 2);
    Matrix C(vect2, 3, 2);
    Matrix D;
    REQUIRE(A.add(B).equal(C));
    REQUIRE(A.add(D).size(1) == 0);
    REQUIRE(A.add(D).size(2) == 0);
}

TEST_CASE("sub method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    std::vector<int> vect1{6, 5, 4, 3, 2, 1};
    std::vector<int> vect2{-5, -3, -1, 1, 3, 5};
    Matrix A(vect, 3, 2);
    Matrix B(vect1, 3, 2);
    Matrix C(vect2, 3, 2);
    Matrix D;
    REQUIRE(A.sub(B).equal(C));
    REQUIRE(A.sub(D).size(1) == 0);
    REQUIRE(A.sub(D).size(2) == 0);
}

TEST_CASE("mult method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vect1{1, 2, 3, 4, 5, 6};
    std::vector<int> vect2{30, 36, 42, 66, 81, 96};
    Matrix A(vect, 3, 3);
    Matrix B(vect1, 3, 2);
    Matrix C(vect2, 3, 2);
    REQUIRE(A.mult(B).equal(C));
}

TEST_CASE("mult method scalar", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    std::vector<int> vect1{2, 4, 6, 8, 10, 12};
    Matrix A(vect, 3, 2);
    Matrix B(vect1, 3, 2);
    REQUIRE(A.mult(2).equal(B));
}

TEST_CASE("pow method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vect1{468, 576, 684, 1062, 1305, 1548, 1656, 2034, 2412};
    std::vector<int> vect2{30, 36, 42, 66, 81, 96, 102, 126, 150};
    std::vector<int> vect3{1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<int> vect4(6, 2);
    Matrix A(vect, 3, 3);
    Matrix B(vect1, 3, 3);
    Matrix C(vect2, 3, 3);
    Matrix D(vect3, 3, 3);
    Matrix E(vect4, 3, 2);
    REQUIRE(A.pow(3).equal(B));
    REQUIRE(A.pow(2).equal(C));
    REQUIRE(A.pow(0).equal(D));
    REQUIRE(A.pow(1).equal(A));
    REQUIRE(E.pow(2).equal(Matrix(std::vector<int>(), 0, 0)));
}

TEST_CASE("trans method", "[Matrix]") {
    std::vector<int> vect{1, 2, 3, 4, 5, 6};
    std::vector<int> vect1{1, 4, 2, 5, 3, 6};
    Matrix A(vect, 3, 2);
    Matrix B(vect1, 2, 3);
    Matrix C;
    REQUIRE(A.trans().equal(B));
    REQUIRE(C.trans().equal(Matrix()));
}