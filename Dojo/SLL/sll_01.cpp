// #0_Diff_Easy
// #0_Comp_Microsoft
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

Suppose you have two linked list 5->4 ( 4 5 )and 5->4->3( 3 4 5) you have to return  a resultant linked list 0->9->3 (3 9 0).

Input:
	In this problem, method takes two argument: the head of the first and second linked list. The function should not read any input from stdin/console.
	The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
	There are multiple test cases. For each test case, this method will be called individually.

Output:
	Add  two numbers represented by linked lists.

Constraints:
	1<=T<=100
	1<=N<=100

Example:
2
2
4 5
3
3 4 5
2
6 3
1
7

Output:
0 9 3
0 7		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;


namespace {

	Node* addTwoLists(Node* first, Node* second) 
	{
		Node* pResultHead = new Node{0, nullptr};
		Node* pResultCurr = pResultHead;
		int carry = 0;

		while (first || second)
		{
			int sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
			if (first)
			{
				first = first->next;
			}
			if (second)
			{
				second = second->next;
			}

			if (sum > 9)
			{
				sum -= 10;
				carry = 1;
			}
			else 
			{
				carry = 0;
			}

			pResultCurr->data = sum;

			if (first || second)
			{
				pResultCurr->next = new Node{ 0, nullptr };
				pResultCurr = pResultCurr->next;
			}
		}

		if (carry)
		{
			pResultCurr->next = new Node{ 1, nullptr };
		}

		return pResultHead;
	}

} // unnamed namespace


void SLL_1(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot,  testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto first  = buildSllReverse(cin);
		auto second = buildSllReverse(cin);

		auto result = addTwoLists(first, second);

		printSll(cout, result);
		
		destroySll(first);
		destroySll(second);
		destroySll(result);
	}
}