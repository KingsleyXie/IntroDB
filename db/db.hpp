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

	void update(std::string table, json data)
	{
		//
	}

	bool getTable(std::string name, BTree<KVNode> &table)
	{
		for (std::map<std::string, BTree<KVNode> >::iterator i
			= tables.begin(); i != tables.end(); ++i)
			if (i->first == name)
			{
				table = i->second;
				return true;
			}
		return false;
	}

	void addTable(std::string name)
	{
		BTree<KVNode> temp;
		if (getTable(name, temp))
			throw "Table name duplicated!\n";

		BTree<KVNode> tb;
		tables[name] = tb;
	}

	void removeTable(std::string name)
	{
		BTree<KVNode> temp;
		if (!getTable(name, temp))
			throw "Table not exists!\n";

		tables.erase(name);
	}
};
