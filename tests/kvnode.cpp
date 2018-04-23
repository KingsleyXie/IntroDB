#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/json.hpp"
using nlohmann::json;

#include "../db/kvnode.hpp"

TEST_CASE( "KVNode Operator Test" ) {
	json data;
	data["foo"] = "bar";
	KVNode nd1(1, data);
	KVNode nd2(2, data);

	data["foo"] = "br";
	KVNode nd3(3, data);
	KVNode nd4(1, data);

	KVNode nd5(5, data);

	REQUIRE( nd1 < nd2 );
	REQUIRE( nd3 >= nd4 );
	REQUIRE( nd1 == nd4 );
}
