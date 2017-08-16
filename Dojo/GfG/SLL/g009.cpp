// #0_Diff_Easy
// #0_Comp_Microsoft
// #SLL

/* http://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
Given a singly linked list, write a function to swap elements pairwise. For example, if the linked list is 
1->2->3->4->5 => 2->1->4->3->5, 
1->2->3->4->5->6 => 2->1->4->3->6->5

Input:
	In this problem, method takes one argument: the head of the linked list. The function should not read any input from stdin/console.
	The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
	There are multiple test cases. For each test case, this method will be called individually.

Output:
	Pairwise swap linked list elements .

Example:
Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7		*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

//!!! Head is passing by value - so can't change a pointer => simple swap
void pairWiseSwap(Node *head)
{
	while (head && head->next)
	{
		std::swap(head->data, head->next->data);
		head = head->next->next;
	}
}

} // unnamed namespace


void g009(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		pairWiseSwap(head);
		printSll(cout, head);
		destroySll(head);
	}
}