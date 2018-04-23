#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/btree.hpp"

TEST_CASE( "B-Tree Test" ) {
	int order = 3;
	BTree tree(order);

	tree.insert(10);
	tree.insert(6);
	tree.insert(11);
	tree.insert(21);
	tree.insert(10);
	tree.insert(8);
	tree.insert(9);
	tree.insert(6);
	tree.insert(7);

	REQUIRE_NOTHROW( tree.traverse() );
}
