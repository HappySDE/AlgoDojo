// #0_Diff_Easy
// #0_Comp_Amazon
// #SLL

/* http://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
Given a linked list, the task is to find the n'th node from the end.  
It is needed to complete a method that takes two argument, head of linked list and an integer n.

Output:
Corresponding to each test case, output a single integer that is the nth integer in the linked list from the end. 
Print -1 if the value of n is greater than the number of elements in the linked list.

Constraints:
1 <= T <= 50
0 <= No of Nodes <= 1000
0 <= Data in Nodes <= 1000

Example:
Input:
2
9 2
1 2 3 4 5 6 7 8 9
4 5
10 -5 -100 5

Output:
8
-1	*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

int getNthFromLast(Node* head, int n)
{
	Node* pFar = head;
	for (int i = 0; i < n; ++i)
	{
		if (!pFar)
		{
			return -1;
		}
		pFar = pFar->next;
	}

	Node* pNear = head;
	while (pFar)
	{
		pFar = pFar->next;
		pNear = pNear->next;
	}

	return pNear->data;
}

} // unnamed namespace


void g021(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		int N;
		cin >> N;
		int result = getNthFromLast(head, N);
		cout << result << '\n';
	}
}