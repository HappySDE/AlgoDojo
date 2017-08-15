// #0_Diff_Easy
// #0_Comp_Microsoft
// #SLL

/* http://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
Given a linked list of 0s, 1s and 2s, sort it.

Input:
1 2 2 1 2 0 2 2

Output:
0 1 1 2 2 2 2 2

1(Test cases)
8(Number of elements in Link List)
1 2 2 1 2 0 2 2 		*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

//Node can't be changed: so change values
void sortList(Node *head)
{
	unsigned values[3] = {0};
	Node* pCurr = head;
	while (pCurr)
	{
		++values[pCurr->data];
		pCurr = pCurr->next;
	}

	pCurr = head;
	for (int j = 0; j < 3; ++j)
	{
		for (unsigned i = 0; i < values[j]; ++i)
		{
			pCurr->data = j;
			pCurr = pCurr->next;
		}
	}
}

} // unnamed namespace


void g012(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		sortList(head);
		printSll(cout, head);
		destroySll(head);
	}
}