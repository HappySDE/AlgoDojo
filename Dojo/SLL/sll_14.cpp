// #0_Diff_Easy
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
Given a singly linked list, rotate the linked list counter-clockwise by k nodes. 
Where k is a given positive integer smaller than or equal to length of the linked list. 
For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40.

Example:
Input:
1
8
1 2 3 4 5 6 7 8
4

Output:
5 6 7 8 1 2 3 4 		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

void rotate(Node **head_ref, int k)
{
	if (!head_ref || k == 0)
	{
		return;
	}

	Node* pTmp = *head_ref;
	for (int i = 0; i < k-1; ++i)
	{
		pTmp = pTmp->next;
	}

	Node* pNewHead = pTmp->next;
	if (pNewHead == nullptr)
	{
		return;
	}
	pTmp->next = nullptr;

	pTmp = *head_ref;
	*head_ref = pNewHead;

	while (pNewHead->next)
	{
		pNewHead = pNewHead->next;
	}
	pNewHead->next = pTmp;
}

} // unnamed namespace


void SLL_14(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		int K;
		cin >> K;
		
		rotate(&head, K);
		
		printSll(cout, head);
		destroySll(head);
	}
}