#include "Headers.h"

// #0_Diff_Easy 
// #0_Comp_Microsoft
// #2DArr #Search

/*  http://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . The task is to find whether element x is present in the matrix or not.

Expected Time Complexity : O(m + n)

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of two space separated integers N and M, denoting the number of element in a row and column respectively.
Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order.
Third line of each test case contains a single integer x, the element to be searched.

Output:	Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply print 0.

Constraints:
	1<=T<=200
	1<=N,M<=30
*/

namespace {

	//Solve the task from a corner where move in one direction is decreasing, and in other - increasing
	unsigned solve(int cols, int rows, unsigned val, const std::vector<unsigned>& matrix)
	{
		int x = cols - 1;
		int y = 0;
		while (x >= 0 && y < rows)
		{
			int index = y*cols + x;
			if (matrix[index] == val)
			{
				return 1;
			}

			if (matrix[index] < val)
			{
				++y;
			}
			else if (matrix[index] > val)
			{
				--x;
			}
		}
		return 0;
	}

} // unnamed namespace

void g002(unsigned run)
{
	FileTestData cin (__FUNCTION__, run);
	Result       cout(__FUNCTION__, run);
	PerfTimer    perf;

	unsigned T;
	cin >> T;
	for (unsigned i = 0; i < T; ++i)
	{
		int N, M;
		cin >> N >> M;

		std::vector<unsigned> matrix(M*N);
		for (int j = 0; j < M*N; ++j)
		{
			cin >> matrix[j];
		}

		unsigned val;
		cin >> val;

		cout << solve(N, M, val, matrix) << '\n';
	}
}