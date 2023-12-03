#pragma once
#include <climits>
class BinomialQueue
{
	typedef struct node
	{
		int key;
		int h;
		node* next, * prev, * child;
		node(int k, int h=0, node* n=nullptr, node* p=nullptr, node* c=nullptr) :key(k), h(h), next(n), prev(p), child(c) {};
	}node;

	node* head;
	/*node* Merge(node* p1, node* p2);*/
	node* Extract(node* &p);
	node* UnionR(node* p1, node* p2);
	node* GetMax();
	node* AddTwoBinomialTreesSameHeight(node* p1, node* p2);
public:
	BinomialQueue() { head = nullptr;  };
	void Insert(int v);
	bool DeleteMax();
	int Max();

};

