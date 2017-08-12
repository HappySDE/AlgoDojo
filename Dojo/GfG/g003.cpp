// #0_Diff_Easy
// #0_Comp_Facebook
// #String

/* http://practice.geeksforgeeks.org/problems/maximum-integer-value/0
Given a string of numbers, the task is to find the maximum value from the string, you can add a ‘+’ or ‘*’ sign between any two numbers.
Note: Add sign between two numbers on the basis of numbers not on the value calculated till that number.
For eg: n = 5120
(((5  + 1 )  + 2 )  + 0 ) = 8 is right.
(((5  + 1 )  * 2 )  + 0 ) =  12 is wrong.

Input:
First line of input contains number of testcases.
Each testcase has a line of input contains a string.

Output:  Print the maximum value obtained from the string.Value can be very large,so print using modulo 10^9+7.

Constraints:
1<=T<=10
1<=length of string<=10^6
0<=number<=9	*/

#include "Headers.h"

namespace {

	unsigned long long solve(const std::string& str)
	{
		if (str.empty())
			return 0;

		unsigned long long ret = str[0] - '0';
		for (size_t i = 0; i < str.length()-1; ++i)
		{
			unsigned curr = str[i]     - '0';
			unsigned next = str[i + 1] - '0';
			if (curr * next >= curr + next) // Here is a catch: >= instead of >
			{
				ret *= next;
			}
			else
			{
				ret += next;
			}
		}
		return ret;
	}

} // unnamed namespace

void g003(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned i = 0; i < T; ++i)
	{
		std::string str;
		cin >> str;
		cout << solve(str) << '\n';
	}
}