#include "BinomialQueue.h"

//BinomialQueue::node* BinomialQueue::Merge(node* p1, node* p2)
//{
//	if (!p1) return p2;
//	if (!p2) return p1;
//
//	node* pp1 = p1;
//	node* pp2 = p2;
//
//	if (pp1->h > pp2->h)
//	{
//		node* temp = pp1;
//		pp1 = pp2;
//		pp2 = temp;
//	}
//	
//	node* n = pp1;
//	pp1 = pp1->next;
//	n->next = nullptr;
//	n->prev = n;
//
//	node* merged=n;
//	
//	while (pp1 && pp2)
//	{
//		if (pp1->h < pp2->h)
//		{
//			if (merged->prev->h == pp1->h)
//			{
//				node* mergePrev = merged->prev;
//				merged->prev = merged->prev->prev;
//				node* added = AddTwoBinomialTreesSameHeight(mergePrev, pp1);
//				merged->prev->next = added;
//
//			}
//			else
//			{
//				merged->prev->next = pp1;
//				pp1->prev = merged->prev;
//				merged->prev = pp1;
//				pp1 = pp1->next; 
//				merged->prev->next = nullptr;
//			}
//			
//		}
//		if (pp1->h > pp2->h)
//		{
//			
//		}
//		// pp1->h == pp2 -> h
//		
//	}
//}

BinomialQueue::node* BinomialQueue::Extract(node* &p)
{
	if (!p) return nullptr;
	node* n = p;
	p = p->next;
	if(p)
		p->prev = n->prev;

	n->next = nullptr;
	n->prev = n;

	return n;
}

BinomialQueue::node* BinomialQueue::UnionR(node* p1, node* p2)
{
	if (!p1) return p2;
	if (!p2) return p1;

	node* t1, * t2, * t3, *p3;

	if (p1->h > p2->h)
	{
		node* temp = p1;
		p1 = p2;
		p2 = temp;
	}

	if (p1->h < p2->h)
	{
		t1 = Extract(p1);
		p3 = UnionR(p1, p2);
		t1->prev = p3->prev;
		t1->next = p3;
		p3->prev = t1;
		return t1;
	}
	// p1->h==p2->h

	t1 = Extract(p1);
	t2 = Extract(p2);
	t3 = AddTwoBinomialTreesSameHeight(t1,t2);
	p3 = UnionR(p1, p2);
	return UnionR(p3, t3);
}

void BinomialQueue::Insert(int v)
{
	node* n = new node(v);
	n->prev = n;
	head=UnionR(head, n);
}

BinomialQueue::node* BinomialQueue::AddTwoBinomialTreesSameHeight(node* p1, node* p2)
{
	if (p2->key > p1->key)
	{
		//swap
		node* tmp = p1;
		p1 = p2;
		p2 = tmp;
	}

	if (p1->h == 0)
	{
		p1->child = p2;
	}
	else
	{
		p2->prev = p1->child->prev;
		p2->prev -> next = p2;
		p1->child->prev = p2;
		/*p1->child->prev->next = p2;
		p2->prev = p1->child->prev;
		p1->child->prev = p2;*/
	}

	p1->h++;
	return p1;
}

int BinomialQueue::Max()
{
	int max = INT_MIN;
	node* p=head;
	while (p)
	{
		if (p->key > max)
			max = p->key;
		p = p->next;
	}
	return max;
}

BinomialQueue::node* BinomialQueue::GetMax()
{
	if (!head) return nullptr;
	node* max = head;
	node* p = head->next;
	while (p)
	{
		if (p->key > max->key)
			max = p;
		p = p->next;
	}
	return max;
}

bool BinomialQueue::DeleteMax()
{
	node* max=GetMax();
	if (!max) return false;

	if (head->next == nullptr)
		head = nullptr;
	else
	{
		//max in the begining
		if (max == head)
		{
			head = max->next;
			max->next->prev = max->prev;
		}
		// max in the end
		else if (max->next == nullptr)
		{
			max->prev->next = nullptr;
			head->prev = max->prev;
		}
		else // max in the middle
		{
			max->next->prev = max->prev;
			max->prev->next = max->next;
		}
	}

	node* p = max->child;
	while (p)
	{
		node* n = Extract(p);
		head = UnionR(n, head);
	}

	delete max;
	return true;
}

//bool BinomialQueue::DeleteMax()
//{
//	if (!head) return false;
//	node* p = head;
//	node* pMax = head;
//	while (p)
//	{
//		if (p->key > pMax->key)
//			pMax = p;
//		p = p->next;
//	}
//	node* t = pMax->child;
//
//	if (pMax->next)
//		pMax->next->prev = pMax->prev;
//	else
//		head->prev = pMax->prev;
//	if (pMax != head)
//		pMax->prev->next = pMax->next;
//	else
//		head = head->next;
//	head = UnionR(head, t);
//	return true;
//}