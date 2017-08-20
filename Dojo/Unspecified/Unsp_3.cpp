// #0_Diff_Easy
// #0_Src_HR
// #Queue

/* https://www.hackerrank.com/challenges/equal-stacks/problem
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. 
You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. 
This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. 
The removals must be performed in such a way as to maximize the height.

Note: An empty stack is still a stack. */

#include "Headers.h"
#include <queue>

void Unsp_3(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	int sz0, sz1, sz2;

	cin >> sz0 >> sz1 >> sz2;

	int sum0 = 0, sum1 = 0, sum2 = 0;
	std::queue<int> q0, q1, q2;
	int tmp;
	for (int i = 0; i < sz0; ++i)
	{
		cin >> tmp;
		q0.push(tmp);
		sum0 += tmp;
	}
	for (int i = 0; i < sz1; ++i)
	{
		cin >> tmp;
		q1.push(tmp);
		sum1 += tmp;
	}

	for (int i = 0; i < sz2; ++i)
	{
		cin >> tmp;
		q2.push(tmp);
		sum2 += tmp;
	}

	while ((sum0 != sum1) || (sum1 != sum2))
	{
		if (sum0 > sum1)
		{
			sum0 -= q0.front();
			q0.pop();
		}
		if (sum0 < sum1)
		{
			sum1 -= q1.front();
			q1.pop();
		}
		if (sum0 > sum2)
		{
			sum0 -= q0.front();
			q0.pop();
		}
		if (sum0 < sum2)
		{
			sum2 -= q2.front();
			q2.pop();
		}
	}

	cout << sum0;
}