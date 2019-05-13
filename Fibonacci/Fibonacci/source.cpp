#include "Headers.h"
#include "Fibonnacci.h"
#include "Timer.h"

void main()
{
	Fibonnacci fibonacci;
	Timer timer; //Timer is used to measure the amound of time takes to both versions of the algoritm
	unsigned int index; //This variable represents the position to calculate in the Fibonacci sequence

	while (true) //Infinite loop to insert diferent values in the "index" variable
	{
		//Insert the position to calculate
		std::cout << "---------------------------------------------------------------------------------\n";
		std::cout << "Insert an index to calculate the corresponding value in the fibonacci's sequence: \n";
		std::cin >> index;

		std::cout << "\nNon-Recursive: \n";
		timer.Start(); //Start to count time
		fibonacci.Calc(index); //Execute the non-recurse Method
		timer.End(); //Finish taking time and print the resulting time
		fibonacci.Print(); //print result

		std::cout << "\n\nRecursive: \n"; //Start to count time
		timer.Start(); //Start to count time
		fibonacci.RecursiveCalc(index); //Execute the recurse Method
		timer.End(); //Finish taking time and print the resulting time
		fibonacci.Print(); //print result
	}

	return;
}