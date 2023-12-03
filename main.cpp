#include <iostream>
#include <chrono>
#include "heap.h"
#include "LeftistHeap.h"
#include "BinomialQueue.h"

void HeapExample();
void LeftistHeapExample();
void BinomialQueueExample();

int main()
{
	
	//LeftistHeapExample();
	BinomialQueueExample();
	return 0;
}

void BinomialQueueExample()
{
	BinomialQueue lh = BinomialQueue();
	lh.Insert(3);
	lh.Insert(5);
	lh.Insert(1);
	lh.Insert(9);
	lh.Insert(2);
	lh.Insert(10);
	lh.Insert(4);
	lh.Insert(7);	
	while(lh.DeleteMax())
	cout << lh.Max()<<endl;
}

void LeftistHeapExample()
{
	LeftistHeap lh = LeftistHeap();

	lh.Insert(3);
	lh.Insert(5);
	lh.Insert(1);
	lh.Insert(9);
	lh.Insert(2);
	lh.Insert(4);
	lh.Insert(7);

	lh.Print();

	cout << lh.GetMax()<<endl;
	lh.DeleteMax();
	cout << lh.GetMax() << endl;
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