#include <iostream>
#include "Headers.h"
#include "Sorter.h"
#include "Timer.h"

void main()
{
	Sorter sort;
	Timer timer;

	unsigned int size;
	unsigned int type;

	std::cout << "Ingresa la cantidad de valores en la muestra\n";
	std::cin >> size;
	std::cout << "En que orden se crearan los valores\n\n  1.- Orden Ascendente\n  2.- Orden Descendente\n  3.- Aleatorio\n\n";
	std::cin >> type;

	if (type == 1)
	{
		sort.IncreasingGen(size);
	}
	else if (type == 2)
	{
		sort.DecreasingGen(size);
	}
	else if(type > 2)
	{
		sort.RandomGen(size);

		if (type != 3)
		{
			std::cout << "Se generaron valores aleatorios";
		}
	}

	timer.Start();
	sort.BubbleSort();
	timer.End();

	sort.Print();
	std::cin.ignore();
}