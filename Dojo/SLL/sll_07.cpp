// #0_Diff_Medium
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1
Given a linked list,performs the following task

Remove alternative nodes from second node
Reverse the removed list.
Append the removed list at the end.

INPUT:
1
8
10 4 9 1 3 5 9 4

OUTPUT:
10 9 3 9 4 5 1 4 		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* reverse(Node* pHead)
{
	if (!pHead)
	{
		return pHead;
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

void rearrange(Node* pHead)
{
	if (!pHead || !pHead->next)
	{
		return;
	}

	Node* pTail1 = pHead;

	Node* pHead2 = pHead->next;
	Node* pTail2 = pHead2;

	Node* pCurr = pHead2->next;

	while (pCurr)
	{
		pTail1->next = pCurr;
		pTail1 = pCurr;
		
		pCurr = pCurr->next;

		if (pCurr)
		{
			pTail2->next = pCurr;
			pCurr = pCurr->next;
			pTail2 = pTail2->next;
		}
		else
		{
			pTail2->next = nullptr;
		}
	}

	pTail1->next = reverse(pHead2);
}

} // unnamed namespace


void SLL_7(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		rearrange(head);
		printSll(cout, head);
		destroySll(head);
	}
}