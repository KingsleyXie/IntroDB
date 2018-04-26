#include "../db/db.hpp"

#define START_NUM 1000000
#define INC_STEP 1000000
#define MAX_SCALE 10000000

class TimeCost
{
private:
	void run(int size)
	{
		std::cout << size << "\t";

		clock_t start;

		// Ordered Int
		BTree<int> tree_oi;

		start = clock();
		for (int i = 0; i < size; ++i)
			tree_oi.insert(i);
		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

		std::cout << "\t";

		// Random Int
		BTree<int> tree_ri;

		start = clock();
		for (int i = 0; i < size; ++i)
			tree_ri.insert(rand());
		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

		std::cout << "\t";

		// Ordered Float
		BTree<float> tree_of;

		start = clock();
		for (int i = 0; i < size; ++i)
			tree_of.insert(float(i) / 1.13251);
		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

		std::cout << "\t";

		// Random Float
		BTree<float> tree_rf;

		start = clock();
		for (int i = 0; i < size; ++i)
			tree_rf.insert(float(rand()) / 1.13251);
		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

		std::cout << "\t";

		// KVNode
		Db kvn("db");
		kvn.addTable("table");
		json data = json::array();

		start = clock();
		for (int i = 0; i < size; ++i)
			kvn.insert("table", data);
		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));
		std::cout << "\n";
	}

public:
	TimeCost()
	{
		std::cout << "Size\t";
		std::cout << "Ordered Int\t";
		std::cout << "Random Int\t";
		std::cout << "Ordered Float\t";
		std::cout << "Random Float\t";
		std::cout << "KVNode\n";

		srand((unsigned)time(NULL));

		for (int size = START_NUM;
			size <= MAX_SCALE;
			size += INC_STEP)
			run(size);
	}
};

int main(int argc, char const *argv[])
{
	TimeCost *tc = new TimeCost();
	return 0;
}
