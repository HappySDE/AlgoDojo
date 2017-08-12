#include "Headers.h"

// #0_Diff_Easy
// #0_Comp_Microsoft
// #Array

/* http://practice.geeksforgeeks.org/problems/transform-the-array/0
Given an array containing integers, zero is considered an invalid number and rest all other numbers are valid. If two nearest valid numbers are equal then double the value of the first one and make the second number as 0.At last move all the valid numbers on the left.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The next line consists of n spaced integers.

Output:
Print the resultant array.

Constraints:
1<=T<=100
1<=N<=10000
1<=A[i]<=10000

Example:
Input:
1
12
2 4 5 0 0 5 4 8 6 0 6 8

Output:
2 4 10 4 8 12 8 0 0 0 0 0	*/
#include <stack>

namespace {

	void transform(std::vector<unsigned>& data)
	{
		std::stack<unsigned> st;

		for (unsigned i = 0; i < data.size(); ++i)
		{
			if (data[i] == 0)
			{
				continue;
			}
			if (st.empty() || st.top() != data[i])
			{
				st.push(data[i]);
			}
			else
			{
				st.top() *= 2; //top returns reference!
			}
		}

		const size_t zeroes = data.size() - st.size();
		const size_t values = st.size();
		for (size_t i = values; i != 0; --i)
		{
			data[i-1] = st.top();
			st.pop();
		}

		for (size_t i = values; i < data.size(); ++i)
		{
			data[i] = 0;
		}
	}

} // unnamed namespace

void g004(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;

	for (unsigned i = 0; i < T; ++i)
	{
		unsigned N;
		cin >> N;
		std::vector<unsigned> data(N);
		for (unsigned j = 0; j < N; ++j)
		{
			cin >> data[j];
		}

		transform(data);

		for (auto j : data)
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
}