#pragma once
#include "Headers.h"

class Sorter
{
	std::vector<unsigned int> m_values;

public:

	void DecreasingGen(unsigned int size);
	void IncreasingGen(unsigned int size);
	void RandomGen(unsigned int size);
	void Print();

	void BubbleSort();

	Sorter() = default;
	~Sorter() = default;
};

