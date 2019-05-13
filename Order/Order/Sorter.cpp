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

void Sorter::BubbleSort()
{
	unsigned int i, j, temp;

	for (i = 0; i < m_values.size() - 1; i++)
	{
		for (j = 0; j < m_values.size() - i - 1; j++)
		{
			if (m_values[j] > m_values[j + 1])
			{
				temp = m_values[j];
				m_values[j] = m_values[j + 1];
				m_values[j + 1] = temp;
			}
		}
	}
}
