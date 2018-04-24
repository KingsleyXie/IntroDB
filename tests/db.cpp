#define CATCH_CONFIG_MAIN
#include "../dependency/catch.hpp"

#include "../db/db.hpp"

TEST_CASE( "B-Tree Db Test" )
{
	Db db("db");
	json data, result;

	SECTION( "Tables Test" )
	{
		REQUIRE_NOTHROW( db.addTable("table1") );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_THROWS_WITH(
			db.addTable("table1"),
			"Table name duplicated!\n"
		);

		REQUIRE_NOTHROW( db.addTable("table2") );
		REQUIRE_NOTHROW( db.traverse() );

		data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", 1, data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.insert("table2", 1, data) );

		data["update"] = "update";
		REQUIRE_NOTHROW( db.update("table1", 1, data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.insert("table2", 2, data) );

		REQUIRE_NOTHROW( db.select("table1", result) );
		std::cout << result;
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_THROWS_WITH(
			db.remove("table1", 2),
			"Provided key is not in the tree!\n"
		);

		REQUIRE_NOTHROW( db.insert("table1", 2, data) );
		std::cout << result;
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.remove("table1", 1) );
		REQUIRE_NOTHROW( db.select("table1", result) );
		std::cout << result;
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_THROWS_WITH(
			db.select("table3", result),
			"Table not exists!\n"
		);

		REQUIRE_NOTHROW( db.removeTable("table2") );
		REQUIRE_THROWS_WITH(
			db.remove("table2", 1),
			"Table not exists!\n"
		);
	}
}
