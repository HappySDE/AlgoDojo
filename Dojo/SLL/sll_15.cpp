// #0_Diff_Basic
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/merge-list-alternatingly/1
Given two linked lists, your task is to complete the function mergeList() which insert's nodes of second list into first list at alternate positions of first list.

For example:
Input:
List1- 5->7->17->13->11
List2- 12->10->2->4->6
Output:
List1- 5->12->7->10->17->2->13->4->11->6
List2- (empty)

The nodes of second list should only be inserted when there are positions available.
Input:
List1- 1->2->3
List2- 4->5->6->7->8
Output:
List1- 1->4->2->5->3->6
List2- 7->8

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
2
9 10
6
5 4 3 2 1 6
5
99 88 77 66 55
5
55 44 33 22 11
Output:
10 6 9 1
2 3 4 5
55 11 66 22 77 33 88 44 99 55		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

void mergeList(Node** p, Node** q)
{
	if (!*p || !*q)
		return;

	Node* pHead = *p;
	Node* pCurr = nullptr;

	Node* f = *p;
	Node* s = *q;

	while (true)
	{
		if (!f)
		{
			break;
		}
		pCurr = f;
		f = f->next;

		if (!s)
		{
			break;
		}

		pCurr->next = s;

		pCurr = pCurr->next;

		s = s->next;
		pCurr->next = f;
	}

	*p = pHead;
	*q = s;
}

} // unnamed namespace


void SLL_15(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto f = buildSllReverse(cin);
		auto s = buildSllReverse(cin);
		mergeList(&f, &s);
		printSll(cout, f); 		destroySll(f);
		printSll(cout, s);		destroySll(s);
	}
}