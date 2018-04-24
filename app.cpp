#include "./db/db.hpp"

int main(int argc, char const *argv[])
{
	json req, res;
	Db db("db_name");

	db.restore("test.json");
	db.traverse();

	return 0;
}
