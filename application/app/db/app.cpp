#include "../../../db/db.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cerr << "\n\tUsage: ./app operation(json-encoded)\n";
	else
	{
		json operation, data;
		std::string db_name, tb_name;
		int op_type;

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

		json result;
		switch (op_type)
		{
			case 0: // count
				std::cout << db.count(tb_name);
				break;

			case 1: // select
				db.select(tb_name, result);
				std::cout << result;
				break;

			case 2: // insert
				db.insert(tb_name, operation["data"]);
				break;

			case 3: // update
				db.update(tb_name, operation["id"], operation["data"]);
				break;

			case 4: // remove
				db.remove(tb_name, operation["id"]);
				break;

			case 5: // addtable
				db.addTable(tb_name);
				break;

			case 6: // removetable
				db.removeTable(tb_name);
				break;

			default:
				throw "Operation Type Error!";
		}

		db.dump(db_name + ".json");
	}
	return 0;
}
