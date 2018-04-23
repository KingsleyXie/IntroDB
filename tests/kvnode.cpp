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
		KVNode nd1(1, data);
		REQUIRE_NOTHROW( kvt.insert(nd1) );
		// REQUIRE_NOTHROW( kvt.traverse() );

		data["test"] = "test";
		KVNode nd2(2, data);
		REQUIRE_NOTHROW( kvt.insert(nd2) );
		// REQUIRE_NOTHROW( kvt.traverse() );

		KVNode nd3(1);
		REQUIRE_NOTHROW( kvt.remove(nd3) );
		// REQUIRE_NOTHROW( kvt.traverse() );

		nd3.key = 233;
		REQUIRE_THROWS_WITH(
			kvt.remove(nd3),
			"Provided key is not in the tree!\n"
		);
	}
}
