#pragma once

class PerfTimer;

class PerfBlock
{
public:
	PerfBlock(PerfTimer& timer, unsigned id);
	~PerfBlock();

private:
	PerfTimer& m_timer;
	const unsigned m_block;
};

class PerfTimer
{
public:
	friend class PerfBlock;

	PerfTimer();
	~PerfTimer();

private:
	void startBlock(unsigned block);
	void stopBlock (unsigned block);

	void printTime(__int64 time) const;

	static const unsigned m_blockAmount = 3;

	__int64 m_cpuFreq;
	__int64 m_testTotalTime;
	__int64 m_blocks[m_blockAmount];
};