#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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

	SECTION( "Insert Operation Test" )
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
	}

	SECTION( "Remove Operation Test" )
	{
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

	SECTION( "Insert Operation Test" )
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
	}

	SECTION( "Remove Operation Test" )
	{
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
