#pragma once
#include "Headers.h"

class Search
{
public:
	
	static int BinarySearchHelper(std::vector<unsigned int>& values, int first, int last, unsigned int number);
	static int BinarySearch(std::vector<unsigned int>& values, unsigned int number);
	static int LinearSearch(std::vector<unsigned int>& values, unsigned int number);

	Search();
	~Search();
};

