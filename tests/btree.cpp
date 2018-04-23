#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../db/btree.hpp"

TEST_CASE( "B-Tree Test" ) {
	int order = 3;
	BTree<int> int_tree(order);

	REQUIRE_THROWS_WITH( int_tree.remove(1), "The tree is empty!\n" );

	int_tree.insert(10); int_tree.insert(6); int_tree.insert(11);
	int_tree.insert(21); int_tree.insert(10); int_tree.insert(8);
	int_tree.insert(9); int_tree.insert(10); int_tree.insert(12);

	int_tree.insert(6); int_tree.traverse(); std::cout << "\n";
	int_tree.remove(9); int_tree.traverse(); std::cout << "\n";
	int_tree.remove(6); int_tree.traverse(); std::cout << "\n";

	int_tree.remove(10); REQUIRE_NOTHROW( int_tree.traverse() );
	REQUIRE_THROWS_WITH( int_tree.remove(233), "Provided key is not in the tree!\n" );

	BTree<float> float_tree(order);
	REQUIRE_THROWS_WITH( float_tree.remove(1), "The tree is empty!\n" );

	float_tree.insert(52.6); float_tree.insert(12.3);
	float_tree.insert(351.336); float_tree.insert(97);
	float_tree.insert(1926.0817); float_tree.traverse();
	REQUIRE_THROWS_WITH( float_tree.remove(10.2), "Provided key is not in the tree!\n" );
}
