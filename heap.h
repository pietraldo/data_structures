#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

class Heap
{
	int* root;
	int max_size;
	int number_of_elements;

public:
	Heap(int max_size_of_heap=63);

	bool Insert(int value); // true if inserted
	void upHeap(int index);
	void downHeap(int index);
	bool deleteMax();

	~Heap();

	//good printing is only when max_size is 2^x-1 and there are numbers from (0-99)
	friend ostream& operator<<(ostream&, const Heap&);
};

