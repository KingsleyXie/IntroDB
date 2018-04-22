#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/btree.hpp"

TEST_CASE( "B-Tree Test" ) {
	BTree tree;

	REQUIRE( tree.getData() == 0 );
}
