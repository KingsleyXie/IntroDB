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

	void select(std::string name, json &result)
	{
		if (!checkTable(name)) throw "Table not exists!\n";

		tables[name].selectAll(result);
	}

	void insert(std::string name, int id, json data)
	{
		if (!checkTable(name)) throw "Table not exists!\n";

		KVNode node(id, data);
		tables[name].insert(node);
	}

	void update(std::string name, int id, json data)
	{
		if (!checkTable(name)) throw "Table not exists!\n";

		KVNode node(id, data);
		tables[name].update(node);
	}

	void remove(std::string name, int id)
	{
		if (!checkTable(name)) throw "Table not exists!\n";

		KVNode node(id);
		tables[name].remove(node);
	}



	bool checkTable(std::string name)
	{
		for (std::map<std::string, BTree<KVNode> >::iterator i
			= tables.begin(); i != tables.end(); ++i)
		{
			if (i->first == name) return true;
		}

		return false;
	}

	void addTable(std::string name)
	{
		if (checkTable(name)) throw "Table name duplicated!\n";

		BTree<KVNode> tb;
		tables[name] = tb;
	}

	void removeTable(std::string name)
	{
		if (!checkTable(name)) throw "Table not exists!\n";

		tables.erase(name);
	}

	void traverse()
	{
		std::cout << "\n\n\n";
		for (int l = 0; l < 75; ++l)
			std::cout << "*";

		std::cout << "\nTraversing Database: " << name;

		for (std::map<std::string, BTree<KVNode> >::iterator i
			= tables.begin(); i != tables.end(); ++i)
		{
			std::cout << "\n";
			for (int l = 0; l < 60; ++l)
				std::cout << "-";

			std::cout << "\nTable: " << i->first;
			std::cout << "\tData: \n";
			i->second.traverse();
		}

		std::cout << "\n";
	}

	void dump(std::ostream& stream)
	{
		//
	}

	void restore()
	{
		//
	}
};
