// #0_Diff_Easy
// #0_Comp_Amazon
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1
Given a singly linked list, rearrange it in a way that all odd position nodes are together and all even positions node are together

Output:	Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 3 2 4
1 3 5 2 4		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* rearrangeEvenOdd(Node* head)
{
	if (!head || !head->next)
		return head;

	Node* pNewHead = head;
	Node* pEvenHead = head->next;

	Node* pOddTail  = head;
	Node* pEvenTail = head->next;

	head = pEvenTail->next;

	bool odd = true;
	while (head)
	{
		if (odd)
		{
			pOddTail->next = head;
			pOddTail = pOddTail->next;
		}
		else
		{
			pEvenTail->next = head;
			pEvenTail = pEvenTail->next;
		}
		head = head->next;
		odd = !odd;
	}

	pOddTail->next = pEvenHead;
	pEvenTail->next = nullptr;

	return pNewHead;
}

} // unnamed namespace


void SLL_4(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot,  testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		head = rearrangeEvenOdd(head);
		printSll(cout, head);
		destroySll(head);
	}
}