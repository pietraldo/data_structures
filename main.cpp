#include <iostream>
#include <chrono>
#include "heap.h"

void HeapExample();

int main()
{
	
	HeapExample();
	
	return 0;
}

void HeapExample()
{
	// checking complexity of building heap in two diffrent way
	srand(time(0));
	for (int i = 10; i < 20; i++)
	{
		int n = pow(2, i);
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = rand() % 100;

		Heap h = Heap(n);
		auto start1 = std::chrono::high_resolution_clock::now();

		// complexity O(nlogn)
		h.createHeapFromUp(arr, n);
		auto stop1 = std::chrono::high_resolution_clock::now();
		
		Heap h2 = Heap(n);
		auto start2 = std::chrono::high_resolution_clock::now();

		// complexity O(n)
		h2.createHeapFromDown(arr, n);
		auto stop2 = std::chrono::high_resolution_clock::now();

		auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
		auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

		cout << "Number of elements: 2^" << i << " Up: " << duration1.count() << " Down: " << duration2.count() << endl;

		delete[]arr;
	}
	

}