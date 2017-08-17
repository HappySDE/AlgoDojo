// #0_Diff_Medium
// #0_Comp_Microsoft
// #Bits

/* http://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0
Given a binary number,  write a program that prints 1 if given binary number is a multiple of 3.  Else prints 0. The given number can be big upto 2^100

It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case contains a string containing 0's and 1's.

Output:
For each test case, output a 1 if string is multiple of 3, else 0.

Constraints:
	1<=T<=100
	1<=Lenght of Input String<=100

Example:
Input:
2
1001
100

Output:
1
0 */

#include "Headers.h"

namespace {

	//Hint:
	//2^0,2,4,6 => %3 = 1
	//2^1,3,5,7 => %3 = 2
	unsigned solve(const std::string& str)
	{
		unsigned sum = 0;

		for (int i = static_cast<int>(str.size()) - 1; i >= 0; --i)
		{
			if (str[i] != '1')
				continue;

			if (i % 2 == 1)
			{
				sum += 2;
			}
			else
			{
				sum += 1;
			}
		}

		return sum % 3 == 0;
	}
	
} // unnamed namespace

void g005(unsigned run)
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