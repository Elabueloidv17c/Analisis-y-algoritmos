#pragma once
#include "Headers.h"

static class Timer
{
	std::chrono::duration<double>		m_result;
	TimePoint							m_start;
	TimePoint							m_end;

	void Print();

public:
	
	Timer() = default;
	~Timer() = default;

	void Start();
	void End();
};

