#include <iostream>
#include "Headers.h"
#include "Search.h"
#include "Sorter.h"
#include "Timer.h"

void main()
{
	Sorter sort;
	Search searcher;
	Timer timer;

	unsigned int size;
	unsigned int type;

	std::cout << "Ingresa la cantidad de valores en la muestra\n";
	std::cin >> size;
	std::cout << "En que orden se crearan los valores\n\n  1.- Orden Ascendente\n  2.- Orden Descendente\n  3.- Aleatorio\n\n";
	std::cin >> type;

	std::vector<unsigned int> values;
	std::vector<unsigned int> values2;

	if (type == 1)
	{
		sort.IncreasingGen(values, size);
	}
	else if (type == 2)
	{
		sort.DecreasingGen(values, size);
	}
	else if(type > 2)
	{
		sort.RandomGen(values, size);

		if (type != 3)
		{
			std::cout << "Se generaron valores aleatorios";
		}
	}

	values2 = values;

	std::cout << "Counting: \n";
	timer.Start();
	sort.CountingSort(values);
	timer.End();

	std::cout << "\nRadix: \n";
	timer.Start();
	sort.RadixSort(values2);
	timer.End();

	int test;	
	std::cout << "\nBinary Search: \n";
	timer.Start();
	test = searcher.BinarySearch(values, values.size() - 1);
	timer.End();
	std::cout << "\n" << "El numero esta en el indice "<< test << "\n\n";

	std::cout << "\nLinear Search: \n";
	timer.Start();
	test = searcher.LinearSearch(values, values.size() - 1);
	timer.End();
	std::cout << "\n" << "El numero esta en el indice " << test << "\n\n";

	sort.Print(values);
	sort.Print(values2);
	
	std::cin.ignore();
	std::cin.get();
}