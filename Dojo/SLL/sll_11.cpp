// #0_Diff_Easy
// #0_Comp_Microsoft
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

Given two linked lists sorted in ascending order. Merge them in-place and return head of the merged list.   
For example, if first list is 10->20->30 and second list is 15->17, then the result list should be 10->15->17->20->30.

It is strongly recommended to do merging in-place using O(1) extra space.

Constraints:
1 <=T<= 200
1 <= size of linked lists <= 1000
1 <= Data in linked list nodes <= 1000

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
2 3 5 10 15 20 40
1 1 2 4 */

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* SortedMerge(Node* first, Node* second)
{
	if (!first)	 return second;
	if (!second) return first;

	Node* pHead = nullptr;
	if (first->data < second->data)
	{
		pHead = first;
		first = first->next;
	}
	else
	{
		pHead = second;
		second = second->next;
	}

	Node* pTail = pHead;
	while (first && second)
	{
		if (first->data < second->data)
		{
			pTail->next = first;
			first = first->next;
			pTail = pTail->next;
		}
		else
		{
			pTail->next = second;
			second = second->next;
			pTail = pTail->next;
		}
	}

	pTail->next = first ? first : second;

	return pHead;
}

} // unnamed namespace


void SLL_11(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto first  = buildSll(cin);
		auto second = buildSll(cin);
		auto merged = SortedMerge(first, second);
		printSll(cout, merged);
		destroySll(merged);
	}
}