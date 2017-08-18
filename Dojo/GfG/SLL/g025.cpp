// #0_Diff_Basic
// #SLL

/* http://practice.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1

Find the Sum of Last N nodes of the Linked List

Given a single linkd list of size M, your task is to complete the function sumOfLastN_Nodes(), which should return the sum of last N nodes of the linked list.

Input:
The function takes two arguments as input, the reference pointer to the head of the linked list and the an integer N.
There will be T test cases and for each test case the function will be called separately.

Constraints:
1<=T<=100
1<=N<=M<=1000

Input:
2
6
5 9 6 3 4 10
3
2
1 2
2
Output:
17
3	*/

#include "Headers.h"
#include "ADT\SLL.h"
using namespace SLL;

namespace {

int sumOfLastN_Nodes(Node* head, int n)
{
    int nodeCount = 0;
    long long sum = 0;
    Node* pTmp = head;
    while (pTmp)
    {
        ++nodeCount;
        sum += pTmp->data;
        pTmp = pTmp->next;
    }
    
    if (n >= nodeCount)
    {
        return static_cast<int>(sum);
    }
    
    nodeCount -= n;
    pTmp = head;
    for (int i = 0; i < nodeCount; ++i)
    {
        
        sum -= pTmp->data;
        pTmp = pTmp->next;
    }
    
    return static_cast<int>(sum);
}

} // unnamed namespace


void g025(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		auto head = buildSll(cin);
		unsigned N;
		cin >> N;

		cout << sumOfLastN_Nodes(head, N) << '\n';
		destroySll(head);
	}
}