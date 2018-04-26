#include "../db/db.hpp"

#define START_NUM 1000000
#define INC_STEP 1000000
#define MAX_SCALE 10000000

void time_test(int size)
{
	std::cout << "\n";
	std::cout << size;
	std::cout << "\t";

	BTree<int> btree;

	clock_t start;
	start = clock();

	for (int i = 0; i < size; ++i)
		btree.insert(i);

	std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));
}

int main(int argc, char const *argv[])
{
	std::cout << "B-Tree<int> Performance Test\n";
	std::cout << "Size\tTime";

	for (int i = START_NUM; i <= MAX_SCALE; i += INC_STEP)
		time_test(i);

	return 0;
}
