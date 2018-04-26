#include "../db/db.hpp"

#define START_NUM 1000000
#define INC_STEP 1000000
#define MAX_SCALE 10000000

template <typename T>
class TimeCost
{
private:
	BTree<T>* tree;

	void run(int size, int type)
	{
		std::cout << "\n";
		std::cout << size;
		std::cout << "\t";

		clock_t start;
		start = clock();

		for (int i = 0; i < size; ++i)
		{
			switch (type)
			{
				case 0: // int
					tree->insert(i);
					break;

				case 1: // int & rand
					tree->insert(rand());
					break;

				case 2: // float
					tree->insert(float(i) / 1.13251);
					break;

				case 3: // float & rand
					tree->insert(float(rand()) / 1.13251);
					break;
			}
		}

		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));
	}

public:
	TimeCost(int type, std::string name)
	{
		BTree<T> *tree = new BTree<T>;

		std::cout << name;
		std::cout << "\nSize\tTime";

		for (int size = START_NUM;
			size <= MAX_SCALE;
			size += INC_STEP)
			run(size, type);

		std::cout << "\n\n\n";
	}

	~TimeCost() { delete tree; }
};

int main(int argc, char const *argv[])
{
	TimeCost<int> *TCA = new TimeCost<int>(0, "B-Tree<int> Performance Test");
	delete TCA;

	TimeCost<int> *TCB = new TimeCost<int>(1, "B-Tree<int & rand> Performance Test");
	delete TCB;

	TimeCost<float> *TCC = new TimeCost<float>(2, "B-Tree<float> Performance Test");
	delete TCC;

	TimeCost<float> *TCD = new TimeCost<float>(3, "B-Tree<float & rand> Performance Test");
	delete TCD;

	std::cout << "Db Performance Test";
	std::cout << "\nSize\tTime";

	for (int size = START_NUM;
		size <= MAX_SCALE;
		size += INC_STEP)
	{
		Db *tree = new Db("db");
		tree->addTable("table");
		json data = json::array();

		std::cout << "\n";
		std::cout << size;
		std::cout << "\t";

		clock_t start;
		start = clock();

		for (int i = 0; i < size; ++i)
			tree->insert("table", data);

		std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));

		delete tree;
	}

	return 0;
}
