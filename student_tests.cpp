#include "catch.hpp"
#include "Matrix.hpp"

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
    std::vector<int> vect{1,2,3,4};
    Matrix A(vect, 2);
    REQUIRE(A.get(0) == 1);
    REQUIRE(A.get(1) == 2);
    REQUIRE(A.get(2) == 3);
    REQUIRE(A.get(3) == 4);

    REQUIRE(A.size(1) == 2);
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

    REQUIRE(A.size(1) == 2);
    REQUIRE(A.size(2) == 3);
    REQUIRE(A.get(100) == INT_MIN);
}