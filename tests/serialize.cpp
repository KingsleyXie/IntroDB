#define CATCH_CONFIG_MAIN
#include "../dependency/catch.hpp"

#include "../dependency/json.hpp"
using json = nlohmann::json;

#include "../db/kvnode.hpp"
#include "../db/btree.hpp"

TEST_CASE( "KVNode B-Tree Serialize Test" )
{
	BTree<KVNode> kvt(3);

	SECTION( "Dump Test" )
	{
		json data;

		data["foo"] = "bar";
		KVNode nd1(1, data);
		REQUIRE_NOTHROW( kvt.insert(nd1) );

		data["test"] = "test";
		KVNode nd2(2, data);
		REQUIRE_NOTHROW( kvt.insert(nd2) );

		nd2.value["emmm"] = "emmm";
		nd2.key = 3; REQUIRE_NOTHROW( kvt.insert(nd2) );
		nd2.key = 4; REQUIRE_NOTHROW( kvt.insert(nd2) );
		nd2.key = 5; REQUIRE_NOTHROW( kvt.insert(nd2) );

		std::fstream file;
		REQUIRE_NOTHROW( file.open("test.json", std::ios::out) );
		REQUIRE_NOTHROW( kvt.dump(file) );
		REQUIRE_NOTHROW( file.close() );
	}

	SECTION( "Restore Test" )
	{
		std::fstream file;
		REQUIRE_NOTHROW( file.open("test.json", std::ios::in) );

		REQUIRE_NOTHROW( kvt.restore(file) );
		REQUIRE_NOTHROW( kvt.traverse() );
		REQUIRE_NOTHROW( file.close() );
	}

	SECTION( "Initial Restore Test" )
	{
		std::fstream file;
		REQUIRE_NOTHROW( file.open("test.json", std::ios::in) );

		json data;
		REQUIRE_NOTHROW(file >> data);

		for (int i = 0; i < data.size(); ++i)
		{
			json row = data[i];
			KVNode nd(row["key"], row["value"]);
			REQUIRE_NOTHROW( kvt.insert(nd) );
		}

		REQUIRE_NOTHROW( kvt.traverse() );

		REQUIRE_NOTHROW( file.close() );
	}
}
