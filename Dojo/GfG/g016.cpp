// #0_Diff_Easy
// #0_Comp_Microsoft
// #SLL

/* http://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
Given pointer to the head node of a linked list, the task is to reverse the linked list.

Output:	Reverse the linked list and return head of the modified list.

Input:
1
6
1 2 3 4 5 6

Output:
6 5 4 3 2 1 		*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

Node* reverse(Node* head)
{
	if (!head)
	{
		return head;
	}

	Node* pPrev = head;
	Node* pCurr = head->next;
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

} // unnamed namespace


void g016(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		head = reverse(head);
		printSll(cout, head);
		destroySll(head);
	}
}