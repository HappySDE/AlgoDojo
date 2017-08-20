#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct FileTestData : public std::ifstream
{
	FileTestData(const std::string& testCaseRoot, unsigned testCase);
};

class Result
{
public:
	Result(const std::string& testCaseRoot, unsigned testCase);
	~Result();

	void setprecision(unsigned precision);
	void fixed();

	template<typename T>
	std::stringstream& operator << (const T& data)
	{
		m_received << data;
		return m_received;
	}

private:
	std::vector<std::string> m_expected;
	std::stringstream        m_received;
};

std::string GetTestCaseRoot(const std::string& testTopic, unsigned taskId);
std::string GetTestCasePath(const std::string& testCaseRoot, unsigned testCase, bool input);