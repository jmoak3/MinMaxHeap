#include <iostream>
#include "Heap.h"
int main()
{
	std::cout << "Min Max Heap" << std::endl;
	Heap min(true);

	min.insert(19);
	min.insert(29);
	min.insert(2);
	min.insert(5);
	min.insert(1);
	min.insert(3);
	min.insert(0);

	std::cout << "expecting 0 1 2 3 5 19 29: ";
	while (!min.isEmpty())
		std::cout << min.pop() << " ";
	std::cout << std::endl;

	Heap max(false);

	max.insert(19);
	max.insert(29);
	max.insert(2);
	max.insert(5);
	max.insert(1);
	max.insert(3);
	max.insert(0);

	std::cout << "expecting 29 19 5 3 2 1 0: ";
	while (!max.isEmpty())
		std::cout << max.pop() << " ";
	std::cout << std::endl;

	std::cin.get();
	return 0;
}