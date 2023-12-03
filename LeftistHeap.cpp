#include "LeftistHeap.h"

node* LeftistHeap::Union(node* p1, node* p2)
{
	node* p;
	if (!p1)
	{
		return p2;
	}
	if (!p2)
	{
		return p1;
	}
	if (p1->key > p2->key)
	{
		p = p1;
		p1->right=Union(p1->right, p2);
	}
	else
	{
		p = p2;
		p2->right = Union(p2->right, p1);
	}

	if (p->left==nullptr || p->left->npl < p->right->npl) //swap left and right heaps
	{
		node* temp = p->right;
		p->right = p->left;
		p->left = temp;
	}
	
	if (p->right == nullptr)
	{
		p->npl = 0;
	}
	else
	{
		p->npl = p->right->npl + 1;
	}

	return p;
}
void LeftistHeap::Print2(node* p)
{
	if (p == nullptr) return;
	cout << p->key << endl;
	Print2(p->left);
	Print2(p->right);
}
void LeftistHeap::Insert(int v)
{
	node* p = new node(v,nullptr,nullptr, 0);
	root = Union(p,root);
}
node* LeftistHeap::DeleteMax()
{
	node* pMax = root;
	root = Union(root->left, root->right);
	pMax->left = nullptr;
	pMax->right = nullptr;
	return pMax;
}
int LeftistHeap::GetMax()
{
	return root->key;
}