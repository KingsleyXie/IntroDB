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

		REQUIRE_NOTHROW( db.removeTable("table2") );
		REQUIRE_THROWS_WITH(
			db.removeTable("table2"),
			"Table not exists!\n"
		);
	}

	SECTION( "Operation Test" )
	{
		REQUIRE_NOTHROW( db.addTable("table1") );

		REQUIRE_THROWS_WITH(
			db.addTable("table1"),
			"Table name duplicated!\n"
		);

		REQUIRE_NOTHROW( db.addTable("table2") );

		data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.insert("table2", data) );

		data["update"] = "update";
		REQUIRE_NOTHROW( db.update("table1", 1, data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.insert("table2", data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.select("table1", result) );
		std::cout << result;

		REQUIRE_THROWS_WITH(
			db.remove("table1", 2),
			"Provided key is not in the tree!\n"
		);

		REQUIRE_NOTHROW( db.insert("table1", data) );
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

TEST_CASE( "Serialize Test" )
{
	Db db("db");
	json data, result;
	std::fstream file;

	SECTION( "Dump Test" )
	{
		REQUIRE_NOTHROW( db.addTable("table1") );
		REQUIRE_NOTHROW( db.addTable("table2") );

		data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.insert("table1", data) );

		REQUIRE_NOTHROW( db.insert("table2", data) );

		data["update"] = "update";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.update("table1", 3, data) );

		REQUIRE_NOTHROW( db.remove("table1", 2) );
		REQUIRE_NOTHROW( db.insert("table1", data) );

		data["update"] = "updated";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( db.insert("table2", data) );
		REQUIRE_NOTHROW( db.insert("table2", data) );
		REQUIRE_NOTHROW( db.remove("table2", 1) );

		REQUIRE_NOTHROW( db.traverse() );

		REQUIRE_NOTHROW( file.open("test.json", std::ios::out) );
		REQUIRE_NOTHROW( db.dump(file) );
		REQUIRE_NOTHROW( file.close() );
	}

	SECTION( "Restore Test" )
	{
		REQUIRE_NOTHROW( file.open("test.json", std::ios::in) );

		REQUIRE_NOTHROW( db.restore(file) );
		REQUIRE_NOTHROW( db.traverse() );
		REQUIRE_NOTHROW( file.close() );

		data["foo"] = "bar";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.insert("table2", data) );

		data["excited"] = "naive";
		REQUIRE_NOTHROW( db.insert("table1", data) );
		REQUIRE_NOTHROW( db.insert("table2", data) );
		REQUIRE_NOTHROW( db.insert("table2", data) );

		REQUIRE_NOTHROW( db.traverse() );
	}
}
