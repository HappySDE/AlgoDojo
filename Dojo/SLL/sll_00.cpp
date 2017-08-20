// #0_Diff_Easy
// #0_Comp_Amazon
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. 
Also, keep the order of even and odd numbers same.

Input:
	The first line of input contains an integer T denoting the number of test cases.
	The first line of each test case is N,N is the number of elements in Linked List.
	The second line of each test case contains N input,elements in Linked List.

Output:
	Print the all even numbers then odd numbers in the modified Linked List.

Constraints:
	1 <= T <= 100
	1 <= N <= 100
	1 <= size of elements <= 1000

Example:
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

	Node* solve(Node* pHead)
	{
		Node* pEvenHead = nullptr, *pEvenCurr = nullptr;
		Node* pOddHead = nullptr, *pOddCurr = nullptr;

		while (pHead)
		{
			if (pHead->data % 2 == 0)
			{
				if (!pEvenCurr)
				{
					pEvenHead = pHead;
					pEvenCurr = pHead;
				}
				else
				{
					pEvenCurr->next = pHead;
					pEvenCurr = pEvenCurr->next;
				}
			}
			else
			{
				if (!pOddCurr)
				{
					pOddHead = pHead;
					pOddCurr = pHead;
				}
				else
				{
					pOddCurr->next = pHead;
					pOddCurr = pOddCurr->next;
				}
			}
			pHead = pHead->next;
		}

		if (pOddCurr)
		{
			pOddCurr->next = nullptr;
		}

		if (!pEvenHead)
		{
			return pOddHead;
		}
		else
		{
			pEvenCurr->next = pOddHead;
		}

		return pEvenHead;
	}

} // unnamed namespace


void SLL_0(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot,  testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		Node* pHead = buildSll(cin);
		pHead = solve(pHead);
		printSll(cout, pHead);
		destroySll(pHead);
	}
}