#define CATCH_CONFIG_MAIN
#include "../dependency/catch.hpp"

unsigned int Factorial( unsigned int number ) {
	if (number == 0)
		throw "excep";
	return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
	SECTION( "Exception" ) {
		REQUIRE_THROWS( Factorial(0), "excep");
	}

	SECTION( "Common" ) {
		REQUIRE( Factorial(1) == 1 );
		REQUIRE( Factorial(2) == 2 );
		REQUIRE( Factorial(3) == 6 );
		REQUIRE( Factorial(10) == 3628800 );
	}
}
