// #0_Diff_Medium
// #0_Comp_Microsoft
// #SLL

/* http://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
If a linked list is given as 1->2->3->4->5->6->7->8->NULL and k = 3 
then output will be 3->2->1->6->5->4->8->7->NULL.

Input:
In this problem, method takes two argument: the head of the linked list and int k. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Reverse the linked list in the group of given size and return the reference of starting node(head) of the reversed Linked list .

Note: If you use "Test" or "Expected Output Button" use below example format
Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5		*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

Node* reverseBlock(Node* pHead, Node* pEnd) //pEnd -> next after last
{
	if (!pHead)
	{
		return pHead;
	}

	Node* pPrev = pHead;
	Node* pCurr = pHead->next;
	pPrev->next = pEnd;

	while (pCurr != pEnd)
	{
		Node* pNext = pCurr->next;
		pCurr->next = pPrev;
		pPrev = pCurr;
		pCurr = pNext;
	}

	return pPrev;
}

Node* reverse(Node* pHead, int k)
{
//#zzz_TODO: SOLVE!!!

}


} // unnamed namespace


void g015(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto pHead = buildSll(cin);
		unsigned K;
		cin >> K;

		pHead = reverse(pHead, K);

		printSll(cout, pHead);
		destroySll(pHead);
	}
}