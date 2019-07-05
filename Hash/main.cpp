#include <iostream>
#include "Headers.h"
#include "Search.h"
#include "Sorter.h"
#include "Timer.h"
#include "Hash.h"

void PrintHashTable(std::vector<std::vector<float>>& table)
{
	for (size_t i = 0; i < table.size(); i++)
	{
		if (table[i].size())
		{
			for (unsigned int j = 0; j < table[i].size(); j++)
			{
				std::cout << "[" << table[i][j] << "]";
			}

			std::cout << "\n";
		}
		else
		{
			std::cout << "[]\n";
		}
	}
}

void RandomFloatVector(std::vector<float>& values, int size)
{
	values.clear();
	values.resize(size);

	for (int i = 0; i < values.size(); i++)
	{
		values[i] = (rand() % 1000 + 1) + (float)rand() / RAND_MAX;
	}
}

void main()
{
	Sorter sort;
	Timer timer;
	
	int size = 0;

	while (size <= 0) 
	{
		std::cout << "Cuantos datos quieres evaluar? \n";
		std::cin >> size;
	}

	std::vector<float> values;
	RandomFloatVector(values, size);

	Hash table;
	table.Initialize(size);

	Hash table2;
	table2.Initialize(size);

	Hash table3;
	table3.Initialize(size);

	for (int i = 0; i < values.size(); i++)
	{
		table.Universal(values[i]);
		table2.Multiplication(values[i]);
		table3.Division(values[i]);
	}

	PrintHashTable(*table3.Get());
}