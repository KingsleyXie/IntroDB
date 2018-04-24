#include "../dependency/json.hpp"
using json = nlohmann::json;

#include "../db/kvnode.hpp"
#include "../db/btree.hpp"

class db
{
public:
	std::string name;

	db(std::string name)
	{
		this->name = name;
	}

	~db() {}
};
