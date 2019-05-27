#include "Search.h"

int Search::LinearSearch(std::vector<unsigned int>& values, unsigned int number)
{
	//This compares every index of the array with the input number
	for (int i = 0; i < values.size(); i++)
	{
		//If the index of the array matches number to search
		if (values[i] == number)
		{
			//Return the index
			return i;
		}
	}

	//Returns an invalid index if the number wasn't find
	return -1;
}

int Search::BinarySearchHelper(std::vector<unsigned int>& values, int first, int last, unsigned int number)
{
	//Divide the array until we have just one element on each child
	if (last >= first)
	{
		//Calculate the middle of the aaray in order to split it
		int middle = first + (last - first) / 2;

		//Check if the middle of the arraya has the number we are looking for
		if (values[middle] == number)
		{
			//If it does, returns the index
			return middle;
		}	

		//If not, call again the algorithm for both halves of the array
		if (values[middle] > number)
		{
			return BinarySearchHelper(values, first, middle - 1, number);
		}

		return BinarySearchHelper(values, middle + 1, last, number);
	}

	//Returns an invalid index if the number wasn't find
	return -1;
}

int Search::BinarySearch(std::vector<unsigned int>& values, unsigned int number)
{
	return BinarySearchHelper(values, 0, values.size() - 1, number);
}

Search::Search()
{
}

Search::~Search()
{
}
