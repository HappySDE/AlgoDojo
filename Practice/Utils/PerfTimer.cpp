#pragma once
#include "Utils\Check.h"
#include "Utils\PerfTimer.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <iostream>

PerfBlock::PerfBlock(PerfTimer& timer, unsigned id)
	: m_timer{timer}
	, m_block{id}
{
	_check(id < PerfTimer::m_blockAmount);
	m_timer.startBlock(m_block);
}

PerfBlock::~PerfBlock()
{
	m_timer.stopBlock(m_block);
}


PerfTimer::PerfTimer()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	m_testTotalTime = li.QuadPart;

	_check(QueryPerformanceFrequency(&li));
	m_cpuFreq = li.QuadPart;

	for (unsigned i = 0; i < m_blockAmount; ++i)
	{
		m_blocks[i] = 0;
	}
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
			std::cout << "Block " << i << ": ";
			printTime(m_blocks[i]);
		}
	}
	std::cout << "Total: ";
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

void PerfTimer::printTime(__int64 time) const
{
	__int64 sec = time / m_cpuFreq;
	std::cout << sec << ',';

	__int64 mcs = (time * 1'000'000) / m_cpuFreq;
	std::cout << mcs / 1000 << '.' << mcs % 1000 << '\n';
}