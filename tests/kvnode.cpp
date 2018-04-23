#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/json.hpp"
using json = nlohmann::json;

#include "../db/kvnode.hpp"
#include "../db/btree.hpp"

TEST_CASE( "KVNode Operator Test" )
{
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

TEST_CASE( "KVNode B-Tree Test" )
{
	BTree<KVNode> kvt(3);

	SECTION( "Empty Tree Test" )
	{
		REQUIRE_THROWS_WITH(
			kvt.remove(1),
			"The tree is empty!\n"
		);
	}

	SECTION( "Operation Test" )
	{
		json data;
		data["foo"] = "bar";

		REQUIRE_NOTHROW( kvt.insert(1, data) );
		REQUIRE_NOTHROW( kvt.traverse() );

		data["test"] = "test";
		REQUIRE_NOTHROW( kvt.insert(2, data) );
		REQUIRE_NOTHROW( kvt.traverse() );

		REQUIRE_NOTHROW( kvt.remove(1) );
		REQUIRE_NOTHROW( kvt.traverse() );

		REQUIRE_THROWS_WITH(
			kvt.remove(233),
			"Provided key is not in the tree!\n"
		);
	}
}
