#include "../dependency/json.hpp"
using json = nlohmann::json;

#include "../db/kvnode.hpp"
#include "../db/btree.hpp"

class Db
{
public:
	std::string name;
	std::map<std::string, BTree<KVNode> > tables;

	Db(std::string name)
	{
		this->name = name;
	}

	~Db() {}

	void addTable(std::string name)
	{
		for (std::map<std::string, BTree<KVNode> >::iterator i
			= tables.begin(); i != tables.end(); ++i)
			if (i->first == name)
				throw "Table name duplicated!\n";

		BTree<KVNode> tb;
		tables[name] = tb;
	}

	void removeTable(std::string name)
	{
		for (std::map<std::string, BTree<KVNode> >::iterator i
			= tables.begin(); i != tables.end(); ++i)
			if (i->first == name) tables.erase(name);
	}
};
