#include "./db/db.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cerr << "\n\tUsage: ./app operation(json-encoded)\n";
	else
	{
		json operation, data;
		std::string db_name, tb_name, op_type;

		try {
			operation = json::parse(argv[1]);

			db_name = operation["db_name"];
			tb_name = operation["tb_name"];
			op_type = operation["op_type"];
		} catch (nlohmann::detail::parse_error) {
			std::cerr << "Request Parse Failed.\n";
			return 0;
		} catch (nlohmann::detail::type_error) {
			std::cerr << "Missing necessary parameters.\n";
			return 0;
		}

		Db db(db_name);

		db.restore(db_name + ".json");
		db.traverse();
	}
	return 0;
}
