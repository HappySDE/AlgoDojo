// #0_Diff_Easy
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
A number (n) is represented in Linked List such that each digit corresponds to a node in linked list. Add 1 to it.

Input:
	You have to complete the method which takes one argument: the head of the linked list. 

Output:
	Your function should return pointer to head of the modified list.

Constraints:
	1 <=T<= 50
	1 <=n<= 10000

Example:

Input:
4
456
123
999
1879

Output:
457
124
1000
1880		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

Node* reverse(Node* head)
{
	if (!head)
	{
		//Nothing to reverse
		return head;
	}

	Node* pPrev = head;
	Node* pCurr = head->next;
	pPrev->next = nullptr;

	while (pCurr)
	{
		Node* pNext = pCurr->next;
		pCurr->next = pPrev;
		pPrev = pCurr;
		pCurr = pNext;
	}

	return pPrev;
}

Node* addOne(Node *head)
{
	if (!head)
	{
		return new Node{1, nullptr};
	}

	head = reverse(head);

	//Add one
	bool carry = true;
	Node* pCurr = head;
	while (pCurr)
	{
		if (pCurr->data == 9 && carry)
		{
			pCurr->data = 0;
			pCurr = pCurr->next;
			carry = true;
		}
		else
		{
			++pCurr->data;
			carry = false;
			break;
		}
	}

	head = reverse(head);

	if (carry)
	{
		head = new Node{ 1, head };
	}

	return head;
}

} // unnamed namespace


void SLL_3(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot,  testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		std::string str;
		cin >> str;
		Node* pHead = nullptr;
		for (size_t i = str.size(); i != 0; --i)
		{
			Node* pNewHead= new Node{ str[i - 1] - '0', pHead};
			pHead = pNewHead;
		}
		pHead = addOne(pHead);

		Node* pToDelete = pHead;
		while (pHead)
		{
			cout << pHead->data;
			pHead = pHead->next;
		}
		cout << '\n';

		destroySll(pToDelete);
	}
}