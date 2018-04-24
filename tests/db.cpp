#define CATCH_CONFIG_MAIN
#include "../dependency/catch.hpp"

#include "../db/db.hpp"

TEST_CASE( "B-Tree Db Test" )
{
	Db db("db");

	SECTION( "Tables Test" )
	{
		REQUIRE_NOTHROW( db.addTable("table1") );

		REQUIRE_THROWS_WITH(
			db.addTable("table1"),
			"Table name duplicated!\n"
		);

		json data; data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", 1, data) );

		data["update"] = "update";
		REQUIRE_NOTHROW( db.update("table1", 1, data) );
		REQUIRE_THROWS_WITH(
			db.remove("table1", 2),
			"Provided key is not in the tree!\n"
		);

		REQUIRE_NOTHROW( db.insert("table1", 2, data) );
		REQUIRE_NOTHROW( db.remove("table1", 1) );
	}
}
