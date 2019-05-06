#pragma once
#include "Headers.h"

class Fibonnacci
{
	unsigned long		m_value;
	unsigned long		Recursive(unsigned int index);

public:

	unsigned long		Calc(unsigned int index);
	void				RecursiveCalc(unsigned int index);
	
	void				Print();

	Fibonnacci();
	~Fibonnacci() = default;
};

