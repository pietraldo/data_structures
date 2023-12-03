#pragma once
#include <iostream>
using namespace std;
typedef struct node
{
	int key;
	node *left, *right;
	int npl;
	node() {};
	node(int key, node* l=nullptr, node* p=nullptr, int npl = 0): key(key), left(l), right(p), npl(npl){};
} node;

class LeftistHeap
{
	node* root=nullptr;

	node* Union(node* l, node* p);
	void Print2(node* n);
public:
	LeftistHeap(){};
	node* DeleteMax();
	void Insert(int v);
	int GetMax();
	void Print() { Print2(root); };
};

