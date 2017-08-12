#include "Headers.h"

// 0_Diff_Easy
// #DynProg #2DArr #PathFind

/* http://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0
You are standing on a point (n, m) and you want to go to origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (n-1, m) or (n, m-1). 
Find the number of paths from point to origin.

Input: The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers n and m representing the point.

Output: Print the total number of paths from point to origin.

Constraints:
	1<=T<=100
	1<=n,m<=100
*/

namespace {

	unsigned solve(unsigned c, unsigned r)
	{
		//Zero initialized, reverse indexed: result will be in data[(r+1)*(c+1)-1]
		std::unique_ptr<unsigned[]> data = std::make_unique<unsigned[]>((r+1)*(c+1));

		//Fill bottommost row with 1
		for (unsigned x = 0; x <= c; ++x)
		{
			data[x] = 1;
		}

		//Fill leftmost column with 0
		for (unsigned y = 1; y <= r; ++y)
		{
			data[y*(c+1)] = 1;
		}

		//Calculate row-by-row result
		for (unsigned y = 1; y <= r; ++y)
		{
			for (unsigned x = 1; x <= c; ++x)
			{
				const unsigned curr = y*(c+1) + x;
				const unsigned left = curr - 1;
				const unsigned bott = curr - c - 1;
				data[curr] = data[left] + data[bott];
			}
		}

		return data[(c+1)*(r+1)-1];
	}

	//#xxx_Perf v2.0: I do not need entire matrix, but only half of it + diagonal. Check for perf in this case

} // unnamed namespace

void g000(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;

	for (unsigned i = 0; i < T; ++i)
	{
		unsigned n, m;
		cin >> n >> m;
		cout << solve(n, m) << '\n';
	}
}