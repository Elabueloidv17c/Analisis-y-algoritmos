#include "Timer.h"

void Timer::Start()
{
	m_start = std::chrono::high_resolution_clock::now();
}

void Timer::End()
{
	m_end = std::chrono::high_resolution_clock::now();
	m_result = m_end - m_start;

	Print();
}

void Timer::Print()
{
	std::cout << "Timer took: " << m_result.count() << " Seconds" << "\n";
}