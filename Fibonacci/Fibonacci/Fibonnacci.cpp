#include "Fibonnacci.h"

Fibonnacci::Fibonnacci()
{
	m_value = 0;
}

void Fibonnacci::RecursiveCalc(unsigned int index)
{
	m_value = Recursive(index);
}

unsigned long Fibonnacci::Recursive(unsigned int index)
{
	if (index <= 1)
	{
		return index;
	}
	else
	{
		return Recursive(index - 1) + Recursive(index - 2);
	}
}

unsigned long Fibonnacci::Calc(unsigned int index)
{
	m_value = 0;
	unsigned int secondLast = 0;
	unsigned int last = 1;

	if (index <= 1)
	{
		m_value = index;
	}

	for (unsigned int i = 1; i < index; ++i) 
	{
		m_value = secondLast + last;
		secondLast = last;
		last = m_value;
	}

	return m_value;
}

void Fibonnacci::Print()
{
	std::cout << "The value for inserted index is: " << m_value << "\n";
}