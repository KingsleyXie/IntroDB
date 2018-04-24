#define CATCH_CONFIG_MAIN
#include "../dependency/catch.hpp"

#include "../dependency/json.hpp"
using json = nlohmann::json;

TEST_CASE( "JSON Test" ) {
	json data;

	data["foo"] = "bar";

	REQUIRE( data["foo"] == "bar" );

	data = {
		{"pi", 3.141},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr},
		{"answer", {
			{"everything", 42}
		}},
		{"list", {1, 0, 2}},
		{"object", {
			{"currency", "USD"},
			{"value", 42.99}
		}}
	};

	REQUIRE( data["object"]["value"] == 42.99 );
}
