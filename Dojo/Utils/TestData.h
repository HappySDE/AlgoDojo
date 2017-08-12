#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct FileTestData : public std::ifstream
{
	FileTestData(const std::string& fileName, unsigned run);
};

class Result
{
public:
	Result(const std::string& fileName, unsigned run);
	~Result();

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

std::string GetTestCasePath(const std::string& testCaseName, unsigned run, bool input);