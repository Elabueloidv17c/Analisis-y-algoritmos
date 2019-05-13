#pragma once
#include "Headers.h"

static class Timer
{
	std::chrono::duration<double>		m_result; //This allocates the resulting elapsed time
	TimePoint							m_start; //This allocates the start time
	TimePoint							m_end; //This allocates the end time
	bool								m_isActive; //This is to determinate if the timer is currently ticking

	void Print(); //Private method to print the resulting elapsed time

public:
	
	Timer() = default;
	~Timer() = default;

	void Start(); //Starts the timer
	void End(); //Stops the timer and calculates the result
};

