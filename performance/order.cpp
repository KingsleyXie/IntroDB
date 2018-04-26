#include "../db/db.hpp"

#define START_NUM 1000
#define INC_STEP 1000
#define MAX_SCALE 50000

void time_test(int order)
{
	std::cout << "\n";
	std::cout << order;
	std::cout << "\t";

	BTree<int> btree(order);

	clock_t start;
	start = clock();

	for (int i = 0; i < 30000000; ++i)
		btree.insert(i);

	std::cout << ((double)(clock() - start) / (CLOCKS_PER_SEC / 1000));
}

int main(int argc, char const *argv[])
{
	std::cout << "Order\tTime";

	for (int i = START_NUM; i <= MAX_SCALE; i += INC_STEP)
		time_test(i);

	return 0;
}
