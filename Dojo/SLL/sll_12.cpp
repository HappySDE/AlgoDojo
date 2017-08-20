// #0_Diff_Easy
// #0_Comp_Microsoft
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1
Given two linked lists sorted in increasing order. Merge them such a way that the result list is in decreasing order. Both the Linked list can be of different sizes.

Constraints:
1 <=T<= 50
1 <= size of linked lists <= 1000

Example:
Input:
2
4 3
5 10 15 40
2 3 20
2 2
1 1
2 4

Output:
40 20 15 10 5 3 2
4 2 1 1  */

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* reverse(Node* pHead)
{
	if (!pHead)
		return nullptr;

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

Node* mergeResult(Node* first, Node* second)
{
	first  = reverse(first);
	second = reverse(second);

	if (!first)
	{
		return second;
	}
	if (!second)
	{
		return first;
	}


	Node* pHead = nullptr;
	if (first->data > second->data)
	{
		pHead = first;
		first = first->next;
	}
	else
	{
		pHead = second;
		second = second->next;
	}

	Node* pTail{ pHead };
	while (first && second)
	{
		if (first->data > second->data)
		{
			pTail->next = first;
			first = first->next;
		}
		else
		{
			pTail->next = second;
			second = second->next;
		}

		pTail = pTail->next;
	}

	pTail->next = first ? first : second;
	return pHead;
}

} // unnamed namespace


void SLL_12(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto first = buildSll(cin);
		auto second = buildSll(cin);
		auto merged = mergeResult(first, second);
		printSll(cout, merged);
		destroySll(merged);		
	}
}