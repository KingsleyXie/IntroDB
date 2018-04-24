#include "./db/db.hpp"

int main(int argc, char const *argv[])
{
	std::fstream file;
	json req, res;
	Db db("db_name");

	file.open("data.json", std::ios::in);
	db.restore(file); file.close();

	file.open("data.json", std::ios::out);
	db.dump(file); file.close();

	return 0;
}
