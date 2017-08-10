#pragma once

class PerfTimer
{
public:
	friend struct PerfBlock0;
	friend struct PerfBlock1;
	friend struct PerfBlock2;

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

struct PerfBlock0 { explicit PerfBlock0(PerfTimer& timer) : m_timer{ timer } { m_timer.startBlock(0); }		~PerfBlock0() { m_timer.stopBlock(0); }	PerfTimer& m_timer; };
struct PerfBlock1 { explicit PerfBlock1(PerfTimer& timer) : m_timer{ timer } { m_timer.startBlock(1); }		~PerfBlock1() { m_timer.stopBlock(1); }	PerfTimer& m_timer; };
struct PerfBlock2 { explicit PerfBlock2(PerfTimer& timer) : m_timer{ timer } { m_timer.startBlock(2); }		~PerfBlock2() { m_timer.stopBlock(2); }	PerfTimer& m_timer; };