#include "Timer.h"

void Timer::Start()
{
	m_isActive = true; //Set to true to avoid a second activation of the timer while active
	m_start = std::chrono::high_resolution_clock::now(); //Gets the current tick
}

void Timer::End()
{
	m_end = std::chrono::high_resolution_clock::now(); //Gets the current tick
	m_result = m_end - m_start; //subtract the start and finish time to get the resulting elapsed time
	
	m_isActive = false; //Set active to false, so it can be actived again

	Print(); //Prints the resulting time
}

void Timer::Print()
{
	std::cout << "Timer took: " << m_result.count() << " Seconds\n"; ////Prints the resulting time in seconds
}