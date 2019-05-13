#include "Fibonnacci.h"

void Fibonnacci::RecursiveCalc(unsigned int index)
{
	m_value = Recursive(index); //This method allocates the resulting value of the Recursive implementation
}

unsigned long Fibonnacci::Recursive(unsigned int index)
{
	if (index <= 1) 
	{
		return index; 	//the first two positions in the sequence are the same value that the index they are in
	}
	else//if the index is greater than 1
	{ //Call the method again to calculate the value of n-1 and n-2
		return Recursive(index - 1) + Recursive(index - 2); //this will repeat until n-1 and n-2 results in 0 and 1 respectibly
	}
}

unsigned long Fibonnacci::Calc(unsigned int index)
{
	m_value = 0; //The first value in the sequense is 0

	//This two variables allocates the values of n-1 and n-2 when index is 2
	unsigned int secondLast = 0;
	unsigned int last = 1;

	if (index <= 1)
	{//the first two positions in the sequence are the same value that the index they are in
		m_value = index;
	}

	for (unsigned int i = 1; i < index; ++i) //This loop iterates staring in index 2 until it reaches the desired index
	{
		m_value = secondLast + last; //Adds n-1 and n-2 to get the current result

		//This prepares the new values of n-1 and n-2 for the next iterarion
		secondLast = last;
		last = m_value;
	}

	return m_value; //Returns the result
}

void Fibonnacci::Print()
{
	std::cout << "The value for inserted index is: " << m_value << "\n"; //Prints the resulting value for the index to the console
}