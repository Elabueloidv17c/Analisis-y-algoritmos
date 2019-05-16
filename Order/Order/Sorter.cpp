#include "Sorter.h"

void Sorter::DecreasingGen(unsigned int size)
{
	m_values.resize(size);

	for (unsigned int i = 0; i < size; i++)
	{
		m_values[i] = size - i - 1;
	}
}

void Sorter::IncreasingGen(unsigned int size)
{
	m_values.resize(size);

	for (unsigned int i = 0; i < size; i++)
	{
		m_values[i] = i;
	}
}

void Sorter::RandomGen(unsigned int size)
{
	m_values.resize(size);

	srand(time(NULL));

	for (unsigned int i = 0; i < size; i++)
	{
		m_values[i] = rand() % size + 0;
	}
}

void Sorter::Print()
{
	if (m_values.size())
	{
		for (unsigned int i = 0; i < m_values.size(); i++)
		{
			std::cout << m_values[i] << "\t";
		}

		std::cout << "\n";
	}
	else
	{
		std::cout << "El contenedor no tiene valores.\n";
	}
}

std::vector<unsigned int> Sorter::BubbleSort(const std::vector<unsigned int>& values)
{
	std::vector<unsigned int> sorted = values;

	unsigned int i, j, temp;

	for (i = 0; i < sorted.size() - 1; i++)
	{
		for (j = 0; j < sorted.size() - i - 1; j++)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}

	return sorted;
}

std::vector<unsigned int> Sorter::InsertionSort(const std::vector<unsigned int>& values)
{
	std::vector<unsigned int> sorted = values;

	int i, key, j;

	for (i = 1; i < sorted.size(); i++)
	{
		key = sorted[i];

		j = i - 1;

		while (j >= 0 && sorted[j] > key)
		{
			sorted[j + 1] = sorted[j];
			j -= 1;
		}

		sorted[j + 1] = key;
	}

	return sorted;
}