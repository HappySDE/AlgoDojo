// #0_Diff_Easy
// #0_Src_GfG
// #Geom

/* http://practice.geeksforgeeks.org/problems/missing-point-of-a-parallelogram/0
Given three coordinate points A, B and C, find the missing point D such that ABCD can be a parallelogram. There can be multiple such points, so print the lexicographically least coordinate.

Input:
The first line of input contains an integer T denoting the number of test cases. 
Each test case contains three lines for each of the point A, B and C with each line containing space separated integers Xi and Yi as coordinates for each of them.

Output:
Print two space separated coordinates of the required point with a precision of 6 decimal places.

Constraints:
1<=T<=100
1<=x,y<=1000 where x and y denote coordinates of points.

Input:
2
1 1
1 0
0 1
3 2
3 4
2 2

Output:
0.000000 0.000000
2.000000 0.000000		*/

#include "Headers.h"

namespace {

struct Point {
	float x, y;
};

bool operator< (const Point& lhs, const Point& rhs)
{
	if (lhs.x != rhs.x )
	{
		return lhs.x < rhs.x;
	}
	return lhs.y < rhs.y;
}

Point solve(const Point& p0, const Point& p1, const Point& p2)
{
	Point ret { p2.x + p1.x - p0.x, p2.y + p1.y - p0.y};
	Point tmp1{ p1.x + p0.x - p2.x, p1.y + p0.y - p2.y };
	if (tmp1 < ret)
	{
		ret = tmp1;
	}

	Point tmp2{ p0.x + p2.x - p1.x, p0.y + p2.y - p1.y };
	if (tmp2 < ret)
	{
		return tmp2;
	}
	return ret;
}

} // unnamed namespace


void Geom_0(const std::string& testCaseRoot, unsigned testCase)
{
	FileTestData cin (testCaseRoot, testCase);
	Result       cout(testCaseRoot, testCase);
	PerfTimer    perf;

	cout.fixed();
	cout.setprecision(6);

	unsigned T;
	cin >> T;
	for (unsigned t = 0; t < T; ++t)
	{
		Point p0, p1, p2;
		cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y;
		Point res = solve(p0, p1, p2);
		cout << res.x << ' ' << res.y << '\n';
	}
}