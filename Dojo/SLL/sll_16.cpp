// #0_Diff_Basic
// #0_Src_GfG
// #SLL

/* http://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
Insert in a Sorted List
Insert data in the linked list in sorted way i.e. order of the list doesn't changes.

Constraints:
1<=T<=100
0<=N<=100
-999<=A[]<=999

Input:
2
6
25 36 47 58 69 80
19
2
50 100
75
Output:
19 25 36 47 58 69 80
50 75 100		*/

#include "Headers.h"
#include "!ADT\SLL.h"
using namespace SLL;

namespace {

void sortedInsert(struct Node** head_ref, int data)
{
    if (!*head_ref)
    {
        *head_ref = new Node{data, nullptr};
        return;
    }
    
    if((*head_ref)->data > data)
    {
        Node* pNew = new Node{data, *head_ref};
        *head_ref = pNew;
        return;
    }
    
    Node* pPrev = *head_ref;
    while (pPrev->next && pPrev->next->data < data)
    {
        pPrev = pPrev->next;
    }
    
    Node* newNode = new Node{data, pPrev->next};
    pPrev->next = newNode;
}
} // unnamed namespace


void SLL_16(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		unsigned data;
		cin >> data;
		sortedInsert(&head, data);
		printSll(cout, head);
		destroySll(head);
	}
}