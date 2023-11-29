#include "heap.h"

Heap::Heap(int max_size_of_heap)
{
	root = new int[max_size_of_heap+1]; // plus guard
	max_size = max_size_of_heap;
	number_of_elements = 0;
	root[0] = INT_MAX;
}

bool Heap::Insert(int value)
{
	if (number_of_elements >= max_size) return false;
	
	number_of_elements++;
	root[number_of_elements] = value;
	upHeap(number_of_elements);
	
	return true;
}

void Heap::upHeap(int index)
{
	while (root[index] > root[index / 2])
	{
		int temp = root[index];
		root[index] = root[index / 2];
		root[index / 2] = temp;
		index /= 2;
	}
}

bool Heap::deleteMax()
{
	if (number_of_elements < 1) return false;
	root[1] = root[number_of_elements];
	number_of_elements--;
	downHeap(1);
	return true;
}

void Heap::downHeap(int index)
{
	while (true)
	{
		int bigger=index*2;
		if (index * 2 > number_of_elements) return;
		if (index * 2 + 1 <= number_of_elements && root[index * 2] < root[index * 2 + 1]) bigger = index * 2 + 1;
		if (root[index] > root[bigger]) return;
		int temp = root[index];
		root[index] = root[bigger];
		root[bigger] = temp;
		index = bigger;
	}
}

Heap::~Heap()
{
	delete root;
}

ostream& operator<<(ostream& out, const Heap& heap)
{
	auto generate_spaces = [](int n) -> string
	{
		string ans = "";
		for (int i = 0; i < n; i++)
			ans += " ";
		return ans;
	};

	int row=0;
	int num_of_elements_in_down_row = heap.max_size* 2;
	for (int i = 1; i <= heap.number_of_elements; i++)
	{
		if (log2((double)(i+1)) >row)
		{
			row++;
			cout << endl;
			num_of_elements_in_down_row /= 2;
			cout << generate_spaces(num_of_elements_in_down_row-1);
		}
		
		int spaces = (heap.max_size + 1);
		int num_of_elements_in_row=pow(2, row-1);
		cout<<(heap.root[i]<10?" ":"") << heap.root[i] << generate_spaces(num_of_elements_in_down_row * 2);
		
	}
	return out;
}