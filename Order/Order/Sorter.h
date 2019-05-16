#pragma once
#include "Headers.h"

class Sorter
{
public:

	std::vector<unsigned int> m_values;

	void DecreasingGen(unsigned int size);
	void IncreasingGen(unsigned int size);
	void RandomGen(unsigned int size);
	void Print();

	std::vector<unsigned int> BubbleSort(const std::vector<unsigned int>& values);
	std::vector<unsigned int> InsertionSort(const std::vector<unsigned int>& values);

	Sorter() = default;
	~Sorter() = default;
};

