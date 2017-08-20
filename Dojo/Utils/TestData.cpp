#include "Utils\Check.h"
#include "Utils\TestData.h"
#include <iostream>
#include <iomanip>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace {

	//Full EXE path is "W:\!Practice\!out\out_Win32\Debug\Practice.exe"
	//"!out" is defined in project properties, so cut the full path to this symbol
	std::string GetSolutionFolder()
	{
		const int buffSize = 4096;
		wchar_t buffer[buffSize] = { 0 };
		_check_GLE(GetModuleFileName(NULL, buffer, buffSize)) << "Can't Get full path";

		std::wstring wstr{ buffer };
		std::string fullPath{ wstr.cbegin(), wstr.cend() };

		auto pos = fullPath.rfind('!');
		return fullPath.substr(0, pos);
	}

} // unnamed namespace

std::string GetTestCaseRoot(const std::string& testTopic, unsigned taskId)
{
	// W:\!Practice\!TestData\SLL\0\ 
	return GetSolutionFolder() + "Dojo\\!TestData\\" + testTopic + '\\' + std::to_string(taskId) + '\\';
}

//////////////////////////////////////////////////////////////////////////
std::string GetTestCasePath(const std::string& testCaseRoot, unsigned testCase, bool input)
{
	std::string path = testCaseRoot + std::to_string(testCase);
	path += input ? ".in" : ".out";
	return path;
}


//////////////////////////////////////////////////////////////////////////
FileTestData::FileTestData(const std::string& testCaseRoot, unsigned testCase)
	: std::ifstream{ GetTestCasePath(testCaseRoot, testCase, true)}
{
	_check(good()) << "Failed to open" << GetTestCasePath(testCaseRoot, testCase, true);
}


//////////////////////////////////////////////////////////////////////////
Result::Result(const std::string& testCaseRoot, unsigned testCase)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "Test case: " << GetTestCasePath(testCaseRoot, testCase, true) << '\n';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	std::ifstream ifs{ GetTestCasePath(testCaseRoot, testCase, false) };
	_check(ifs.good());

	std::string line;
	while (std::getline(ifs, line))
	{
		m_expected.push_back(line);
	}
}

void Result::setprecision(unsigned precision)
{
	m_received << std::setprecision(precision);
}

void Result::fixed()
{
	m_received << std::fixed;
}


Result::~Result()
{
	std::vector<std::string> received;
	std::string str;
	while (getline(m_received, str))
	{
		received.push_back(str);
	}

	if (received.size() != m_expected.size())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "Invalid result count:\n";
		std::cout << "Received = " << received.size() << " Expected = " << m_expected.size() << '\n';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}

	bool ok = true;
	for (size_t i = 0; i < received.size(); ++i)
	{
		if (received[i] != m_expected[i])
		{
			ok = false;
			break;
		}
	}

	if (ok)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "Correct!!!\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Invalid result:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	for (size_t i = 0; i < received.size(); ++i)
	{
		std::cout << "Expected[" << i << "]  " << m_expected[i] << '\n';
		std::cout << "Received[" << i << "]  " << received[i] << '\n';
	}
	std::cout << "\n\n";
}