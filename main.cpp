#include <iostream>

#include "heap.h"

int main()
{
	Heap h = Heap(15);
	
	h.Insert(12);
	h.Insert(13);
	h.Insert(16);
	h.Insert(20);
	h.Insert(10);
	h.Insert(9);
	h.Insert(23);
	h.Insert(18);
	h.Insert(27);
	h.Insert(3);
	h.Insert(22);
	h.Insert(21);
	h.Insert(20);
	h.Insert(29);
	h.Insert(40);
	h.Insert(1);
	h.Insert(14);
	h.Insert(13);
	h.Insert(18);
	h.Insert(23);

	cout << h;
	while (h.deleteMax())
	{
		cout <<endl<< "------------------------------------";
		cout << endl << h;
	}
	
	cout << h;
	return 0;
}