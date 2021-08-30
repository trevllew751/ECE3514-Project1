#include "catch.hpp"
#include "Matrix.hpp"

TEST_CASE( "default constructor", "[Matrix]" )
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
