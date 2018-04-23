#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/btree.hpp"

TEST_CASE( "B-Tree Test" ) {
	int order = 3;
	BTree tree(order);

	REQUIRE_NOTHROW( tree.search(1) );
	REQUIRE_NOTHROW( tree.traverse() );
}
