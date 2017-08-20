// #0_Diff_Easy
// #0_Comp_Microsoft
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
Given a singly linked list, delete middle  of the linked list. For example, 
if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5

If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.

If the input linked list is NULL, then it should remain NULL.

If the input linked list has 1 node, then this node should be deleted and new head should be returned.

Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=value<= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
1 2 4 5
2 4 6 5 1	*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* deleteMid(Node *head)
{
	if (!head)
	{
		return nullptr;
	}

	if (head->next == nullptr)
	{
		delete head;
		return nullptr;
	}

	Node* pCurr = head;
	unsigned count = 0;
	while (pCurr)
	{
		++count;
		pCurr = pCurr->next;
	}

	count = count / 2 - 1; // -1 => for prev

	Node* pPrev = head;
	for (unsigned i = 0; i < count; ++i)
	{
		pPrev = pPrev->next;
	}

	pCurr = pPrev->next;
	pPrev->next = pCurr->next;
	delete pCurr;

	return head;	
}

} // unnamed namespace


void SLL_9(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		head = deleteMid(head);
		printSll(cout, head);
		destroySll(head);
	}
}