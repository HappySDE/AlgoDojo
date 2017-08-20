// #0_Diff_Medium
// #0_Comp_SAP
// #0_Src_GfG
// #Bits

/* http://practice.geeksforgeeks.org/problems/bleak-numbers/0
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Examples :

3 is not Bleak as it can be represented
as 2 + countSetBits(2).

4 is t Bleak as it cannot be represented
as sum of a number x and countSetBits(x)
for any number x.


Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line. The first line of each test case contains a single integer N to be checked for Bleak.

Output:
Print "1" or "0" (without quotes) depending on whether the number is Bleak or not.

Constraints:
1 <= T <= 1000
1 <= N <= 10000		*/

#include "Headers.h"

namespace {

unsigned CountBits(unsigned n)
{
	unsigned count = 0;
	while (n)
	{
		n &= (n - 1);
		++count;
	}
	return count;
}

int solve(unsigned X)
{
	//Only text for [X-maxSetBits; X)
	unsigned maxSetBits = static_cast<unsigned>(log2(X) + 1);
	for (unsigned y = X - maxSetBits; y < X; ++y)
	{
		if (y + CountBits(y) == X)
		{
			return 0;
		}
	}
	return 1;
}

} // unnamed namespace


void Bits_2(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin(testCaseRoot,  testCase);
	Result       cout(testCaseRoot, testCase);

	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		unsigned X;
		cin >> X;
		cout << solve(X) << '\n';
	}
}