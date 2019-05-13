#pragma once
#include "Headers.h"

class Fibonnacci
{
	unsigned long		m_value; //Allocates the result of the algorithm
	unsigned long		Recursive(unsigned int index); //Private method that returns the resulting value in a recursive implementation

public:

	//This method allocates the resulting value of the Recursive implementation in "m_value"
	void				RecursiveCalc(unsigned int index); 
	
	unsigned long		Calc(unsigned int index); //non-recursive implementation
	
	void				Print(); //Prints the resulting value

	Fibonnacci() = default;
	~Fibonnacci() = default;
};

