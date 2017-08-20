// #0_Diff_Easy
// #0_Comp_Amazon
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:

M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
After 2 nodes 2 nodes will be deleted. Deleted Nodes 3->4 and 7->8
Output: Linked List: 1->2->5->6

Example:
Input:
1
8
9 1 3 5 9 4 10 1
2 1
Output : 9 1 5 9 10 1 	*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

void linkdelete(Node* head, int M, int N)
{
	Node* pCurr = head;
	while (true)
	{
		for (int i = 0; i < M-1; ++i)
		{
			if (!pCurr)
			{
				break;
			}
			pCurr = pCurr->next;
		}
		
		Node* pPrev = pCurr;
		if (!pCurr)
		{
			break;
		}

		pCurr = pCurr->next;

		for (int i = 0; i < N; ++i)
		{
			if (!pCurr)
			{
				break;
			}

			Node* pTmp = pCurr;
			pCurr = pCurr->next;
			delete pTmp;
		}
		pPrev->next = pCurr;
	}
}

} // unnamed namespace


void SLL_6(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		int M, N;
		cin >> M >> N; //!!! input order changed
		linkdelete(head, M, N);
		printSll(cout, head);
		destroySll(head);
	}
}