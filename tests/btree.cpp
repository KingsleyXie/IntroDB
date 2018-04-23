#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/json.hpp"
using json = nlohmann::json;

#include "../db/btree.hpp"

int order = 3;

TEST_CASE( "Int B-Tree Test" )
{
	BTree<int> int_tree(order);

	SECTION( "Empty Tree Test" )
	{
		REQUIRE_THROWS_WITH(
			int_tree.remove(1),
			"The tree is empty!\n"
		);
	}

	SECTION( "Operation Test" )
	{
		REQUIRE_NOTHROW( int_tree.insert(10) );
		REQUIRE_NOTHROW( int_tree.insert(6) );
		REQUIRE_NOTHROW( int_tree.insert(11) );
		REQUIRE_NOTHROW( int_tree.insert(21) );

		REQUIRE_NOTHROW( int_tree.traverse() );

		REQUIRE_NOTHROW( int_tree.insert(10) );
		REQUIRE_NOTHROW( int_tree.insert(8) );
		REQUIRE_NOTHROW( int_tree.insert(9) );
		REQUIRE_NOTHROW( int_tree.insert(10) );
		REQUIRE_NOTHROW( int_tree.insert(12) );
		REQUIRE_NOTHROW( int_tree.insert(6) );

		REQUIRE_NOTHROW( int_tree.traverse() );

		REQUIRE_NOTHROW( int_tree.remove(9) );
		REQUIRE_NOTHROW( int_tree.traverse() );

		REQUIRE_NOTHROW( int_tree.remove(6) );
		REQUIRE_NOTHROW( int_tree.traverse() );

		REQUIRE_NOTHROW( int_tree.remove(10) );
		REQUIRE_NOTHROW( int_tree.traverse() );

		REQUIRE_THROWS_WITH(
			int_tree.remove(233),
			"Provided key is not in the tree!\n"
		);
	}
}

TEST_CASE( "Float B-Tree Test" )
{
	BTree<float> float_tree(order);

	SECTION( "Empty Tree Test" )
	{
		REQUIRE_THROWS_WITH(
			float_tree.remove(1),
			"The tree is empty!\n"
		);
	}

	SECTION( "Operation Test" )
	{
		REQUIRE_NOTHROW( float_tree.insert(52.6) );
		REQUIRE_NOTHROW( float_tree.insert(12.3) );
		REQUIRE_NOTHROW( float_tree.insert(351.336) );
		REQUIRE_NOTHROW( float_tree.insert(97) );
		REQUIRE_NOTHROW( float_tree.insert(1926.0817) );

		REQUIRE_NOTHROW( float_tree.traverse() );

		REQUIRE_NOTHROW( float_tree.insert(2.3) );
		REQUIRE_NOTHROW( float_tree.insert(17) );
		REQUIRE_NOTHROW( float_tree.insert(5464511) );

		REQUIRE_NOTHROW( float_tree.traverse() );

		REQUIRE_NOTHROW( float_tree.remove(2.3) );
		REQUIRE_NOTHROW( float_tree.traverse() );

		REQUIRE_NOTHROW( float_tree.remove(97) );
		REQUIRE_NOTHROW( float_tree.traverse() );

		REQUIRE_THROWS_WITH(
			float_tree.remove(10.2),
			"Provided key is not in the tree!\n"
		);
	}
}

TEST_CASE( "JSON B-Tree Test" )
{
	BTree<json> json_tree(order);

	json data;
	data["foo"] = "bar";

	SECTION( "Empty Tree Test" )
	{
		REQUIRE_THROWS_WITH(
			json_tree.remove(data),
			"The tree is empty!\n"
		);
	}

	SECTION( "Operation Test" )
	{
		REQUIRE_NOTHROW( json_tree.insert(data) );
		data["test"] = "emmm"; REQUIRE_NOTHROW( json_tree.insert(data) );
		data["emmm"] = "test"; REQUIRE_NOTHROW( json_tree.insert(data) );

		REQUIRE_NOTHROW( json_tree.traverse() );
		REQUIRE_NOTHROW( json_tree.remove(data) );
		REQUIRE_NOTHROW( json_tree.traverse() );

		REQUIRE_THROWS_WITH(
			json_tree.remove(data),
			"Provided key is not in the tree!\n"
		);
	}
}
