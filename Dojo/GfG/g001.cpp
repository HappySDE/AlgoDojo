// 0_Diff_Basic
// #Graph #PathFind

/* http://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. 
The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case contains a value of n.

Output:
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n <=1000		*/

#include "Headers.h"

namespace {

	unsigned solve(unsigned n)
	{
		unsigned steps = 0;
		while (n != 1)
		{
			if (n % 3 == 0)
			{
				n = n / 3;
			}
			else
			{
				--n;
			}
			++steps;
		}
		return steps;
	}

} // unnamed namespace

void g001(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned i = 0; i < T; ++i)
	{
		unsigned n;
		cin >> n;
		cout << solve(n) << '\n';
	}
}