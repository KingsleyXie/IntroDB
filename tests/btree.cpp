#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/btree.hpp"

TEST_CASE( "B-Tree Test" ) {
	int order = 3;
	BTree tree(order);

	REQUIRE_THROWS_WITH( tree.remove(1), "The tree is empty!\n" );

	tree.insert(10);
	tree.insert(6);
	tree.insert(11);
	tree.insert(21);
	tree.insert(10);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);
	tree.insert(12);
	tree.insert(215);
	tree.insert(6);
	tree.traverse();
	std::cout << "\n";
	tree.remove(9);
	tree.traverse();
	std::cout << "\n";
	tree.remove(6);
	tree.traverse();
	std::cout << "\n";
	tree.remove(10);

	REQUIRE_NOTHROW( tree.traverse() );
	REQUIRE_THROWS_WITH( tree.remove(233), "Provided key is not in the tree!\n" );
}
