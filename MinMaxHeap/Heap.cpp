#include "Heap.h"
#include <iostream>

#include "Heap.h"
#include <iostream>
#include <algorithm>


bool Heap::outOfBounds(int index)
{
	return (index >= heap.size() || index == 0);
}

void Heap::swap(int parent, int child)
{
	std::vector<int>::iterator parentIt = heap.begin() + parent;
	std::vector<int>::iterator childIt = heap.begin() + child;
	std::iter_swap(parentIt, childIt);
}

bool Heap::floatUp(int index)
{
	int parent = heap.at(index / 2);
	int child = heap.at(index);
	if (isMin ? (parent > child) : (parent < child))
	{
		swap(index / 2, index);
		return floatUp(index / 2);
	}
	else if (parent == child)
	{
		std::cout << "Conflict. Freak out" << std::endl;
		return false;
	}
	else
	{
		//bubbled enough
		return true;
	}
}

bool Heap::sink(int index)
{
	int invalid = isMin ? INT_MAX : INT_MIN;
	int parent = heap.at(index);
	bool hasLeft = !outOfBounds(index * 2);
	bool hasRight = !outOfBounds(index * 2 + 1);
	int left = hasLeft ? heap.at(index * 2) : invalid;
	int right = hasRight ? heap.at(index * 2 + 1) : invalid;

	if (isMin)
	{
		if (left < right && left < parent)
		{
			swap(index, index * 2);
			return sink(index * 2);
		}
		else if (right < left && right < parent)
		{
			swap(index, index * 2 + 1);
			return sink(index * 2 + 1);
		}
	}
	else
	{
		if (left > right && left > parent)
		{
			swap(index, index * 2);
			return sink(index * 2);
		}
		else if (right > left && right > parent)
		{
			swap(index, index * 2 + 1);
			return sink(index * 2 + 1);
		}
	}
	return true;
}

bool Heap::insert(int newValue)
{
	//Good one 
	heap.insert(heap.end(), newValue);
	bool result = floatUp(heap.size() - 1);
	return result;
}

int Heap::pop()
{
	if (isEmpty())
	{
		std::cout << "called pop on empty heap." << std::endl;
		return isMin ? INT_MAX : INT_MIN;
	}
	int val = heap.at(1);
	if (heap.size() > 1)
		swap(1, heap.size() - 1);
	heap.erase(heap.end() - 1);
	if (!isEmpty()) sink(1);
	return val;
}

int Heap::size()
{
	return heap.size() - 1;
}

bool Heap::isEmpty()
{
	return heap.size() == 1;
}

void Heap::printOut()
{
	std::cout << "Printing heap: ";
	std::vector<int>::iterator it = heap.begin();
	for (; it != heap.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}