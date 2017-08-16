// #yyy_FILL_ME: 0_Diff_<Easy,Medium,Hard,Basic,School
// #yyy_FILL_ME: 0_Comp_
// #yyy_FILL_ME: hash-tags

/* http://practice.geeksforgeeks.org/problems/rearrange-linked-list-in-place/1
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.

Constraints:
1 <=T<= 50
1 <= size of linked lists <= 100

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 4 2 3
1 5 2 4 3		*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

Node* split(Node* pHead)
{
	if (!pHead || !pHead->next)
	{
		return nullptr;
	}

	Node* pSlow = pHead;
	Node* pFast = pHead->next;

	while (pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}

	Node* pSecond = pSlow->next;
	pSlow->next = nullptr;
	
	return pSecond;
}

Node* reverse(Node* pHead)
{
	if (!pHead)
	{
		return nullptr;
	}

	Node* pPrev = pHead;
	Node* pCurr = pHead->next;
	pPrev->next = nullptr;
	
	while (pCurr)
	{
		Node* pNext = pCurr->next;
		pCurr->next = pPrev;
		pPrev = pCurr;
		pCurr = pNext;
	}

	return pPrev;
}

void merge(Node* pFirst, Node* pSecond)
{
	Node* pTmp = pFirst;
	Node* pCurr = nullptr;
	while (pFirst)
	{
		pCurr = pFirst;
		pFirst = pFirst->next;
		
		pCurr->next = pSecond;
		pCurr = pCurr->next;

		if (!pCurr)
			break;

		pSecond = pSecond->next;
		pCurr->next = pFirst;
	}
}


Node* inPlace(Node* root)
{
	if (!root || !root->next || !root->next->next)
	{
		return root;
	}

	Node* pSecond = split(root); //Find mid & split
	pSecond = reverse(pSecond);
	merge(root, pSecond);

	return root;
}

} // unnamed namespace


void g018(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		head = inPlace(head);
		printSll(cout, head);
		destroySll(head);
	}
}