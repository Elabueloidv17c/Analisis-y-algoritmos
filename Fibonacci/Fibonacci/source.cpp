#include "Headers.h"
#include "Fibonnacci.h"
#include "Timer.h"

void main()
{
	Timer timer;
	Fibonnacci fibonacci;
	unsigned int index;

	while (true)
	{
		std::cout << "---------------------------------------------------------------------------------\n";
		std::cout << "Insert an index to calculate the corresponding value in the fibonacci's sequence: \n";
		std::cin >> index;

		std::cout << "Non-Recursive: \n";
		timer.Start();
		fibonacci.Calc(index);
		fibonacci.Print();
		timer.End();

		std::cout << "Non-Recursive: \n";
		timer.Start();
		fibonacci.RecursiveCalc(index);
		fibonacci.Print();
		timer.End();
	}

	return;
}