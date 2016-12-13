#pragma once
#include <vector>

class Heap
{
public:
	Heap(bool newIsMin) : heap(), isMin(newIsMin) { isMin ? heap.insert(heap.begin(), INT_MIN) : heap.insert(heap.begin(), INT_MAX);  }
	~Heap() {}

	bool insert(int newValue);
	int pop();
	int size();
	bool isEmpty();

private:
	bool outOfBounds(int index);
	void swap(int parent, int child);
	bool floatUp(int index);
	bool sink(int index);
	void printOut();

	bool isMin;
	std::vector<int> heap;
};
