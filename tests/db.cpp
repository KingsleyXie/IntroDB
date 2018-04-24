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

		data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", 1, data) );
		REQUIRE_NOTHROW( db.traverse() );

		data["update"] = "update";
		REQUIRE_NOTHROW( db.update("table1", 1, data) );

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
			db.select("table2", result),
			"Table not exists!\n"
		);

		REQUIRE_THROWS_WITH(
			db.remove("table2", 1),
			"Table not exists!\n"
		);
	}
}
