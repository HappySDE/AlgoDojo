#include "Utils\Check.h"
#include "Utils\Misc.h"
#include "Utils\TestData.h"
#include <exception>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define TOPIC_ID String
#define TASK_ID  0

//geom + 1 => geom_1 with '_' inbetween
#define PPCAT_HELPER(A, B) A##_##B
#define PPCAT(A, B) PPCAT_HELPER(A, B)

#define STRINGIZE_HELPER(A) #A
#define STRINGIZE(A) STRINGIZE_HELPER(A)

#define TEST_CASE_NAME PPCAT(TOPIC_ID, TASK_ID)

void TEST_CASE_NAME(const std::string& testCaseRoot, unsigned testData);

void main()
try
{
	StartMemLeakDetection();

	std::string testCaseRoot = GetTestCaseRoot(STRINGIZE(TOPIC_ID), TASK_ID);

	bool oneTaskExecuted = false;

	for (unsigned testCase = 0; testCase < 50; ++testCase)
	{
		const auto inputData = GetTestCasePath(testCaseRoot, testCase, true);
		if (IsFileExists(inputData.c_str()))
		{
			//Test cases might be in not continues order: 0, 5, 10 ...
			TEST_CASE_NAME(testCaseRoot, testCase);

			oneTaskExecuted = true;
		}
	}

	_check(oneTaskExecuted) << "No test cases for" << testCaseRoot;
}
catch (std::exception& e)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Exception: " << e.what() << '\n';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}