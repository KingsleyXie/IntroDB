#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "tests/kvnode.hpp"

#include "../db/json.hpp"
using nlohmann::json;

TEST_CASE( "KVNode Operator Test" ) {
	KVNode<int, int> nd;

	REQUIRE( Factorial(1) == 1 );
}
