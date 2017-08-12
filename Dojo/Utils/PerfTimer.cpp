#pragma once
#include "Utils\Check.h"
#include "Utils\PerfTimer.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>


PerfTimer::PerfTimer()
{
	LARGE_INTEGER li;
	_check(QueryPerformanceFrequency(&li));
	m_cpuFreq = li.QuadPart;

	for (unsigned i = 0; i < m_blockAmount; ++i)
	{
		m_blocks[i] = 0;
	}

	QueryPerformanceCounter(&li);
	m_testTotalTime = li.QuadPart;
}

PerfTimer::~PerfTimer()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	m_testTotalTime = li.QuadPart - m_testTotalTime;

	for (unsigned i = 0; i < m_blockAmount; ++i)
	{
		if (m_blocks[i] != 0)
		{
			std::cout << "Block" << i << ": ";
			printTime(m_blocks[i]);
		}
	}
	std::cout << "Total:  ";
	printTime(m_testTotalTime);
}


void PerfTimer::startBlock(unsigned block)
{
	_check(m_blocks[block] == 0) << "Block" << block << "is already started";

	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	m_blocks[block] = li.QuadPart;
}

void PerfTimer::stopBlock(unsigned block)
{
	_check(m_blocks[block] != 0) << "Block" << block << "has not been started";

	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	m_blocks[block] = li.QuadPart - m_blocks[block];
}

namespace {

	// custom numpunct with grouping:
	struct my_numpunct : std::numpunct<char> {
		std::string do_grouping() const { return "\03"; }
	};

} // unnamed namespace

void PerfTimer::printTime(__int64 time) const
{
	std::locale loc(std::cout.getloc(), new my_numpunct);
	std::cout.imbue(loc);
	std::cout.width(15);

	std::cout << (time * 1'000'000) / m_cpuFreq << " mcs\n";
}