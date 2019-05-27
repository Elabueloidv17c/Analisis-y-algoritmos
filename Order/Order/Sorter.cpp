#include "Sorter.h"

//----------------------------------------------------------------------------------------------------
//Utility methods
//----------------------------------------------------------------------------------------------------

void Sorter::DecreasingGen(std::vector<unsigned int>& values, const unsigned int& size)
{
	values.resize(size);

	for (unsigned int i = 0; i < size; i++)
	{
		values[i] = size - i - 1;
	}
}

void Sorter::IncreasingGen(std::vector<unsigned int>& values, const unsigned int& size)
{
	values.resize(size);

	for (unsigned int i = 0; i < size; i++)
	{
		values[i] = i;
	}
}

void Sorter::RandomGen(std::vector<unsigned int>& values, const unsigned int& size)
{
	values.resize(size);

	srand(time(NULL));

	for (unsigned int i = 0; i < size; i++)
	{
		values[i] = rand() % size + 0;
	}
}

void Sorter::Print(std::vector<unsigned int>& values)
{
	if (values.size())
	{
		for (unsigned int i = 0; i < values.size(); i++)
		{
			std::cout << values[i] << "\t";
		}

		std::cout << "\n";
	}
	else
	{
		std::cout << "El contenedor no tiene valores.\n";
	}
}

//----------------------------------------------------------------------------------------------------
//Sorting methods
//----------------------------------------------------------------------------------------------------

void Sorter::BubbleSort(std::vector<unsigned int>& values)
{
	unsigned int i, j, temp;

	for (i = 0; i < values.size() - 1; i++)
	{
		for (j = 0; j < values.size() - i - 1; j++)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

void Sorter::InsertionSort(std::vector<unsigned int>& values)
{
	int i, key, j;

	for (i = 1; i < values.size(); i++)
	{
		key = values[i];

		j = i - 1;

		while (j >= 0 && values[j] > key)
		{
			values[j + 1] = values[j];
			j -= 1;
		}

		values[j + 1] = key;
	}
}

unsigned int Sorter::QuickSortSwapper(std::vector<unsigned int>& values, int low, int high)
{
	int pivot = values[high]; //Pivot is at the end of the current vector child

	int Low = (low - 1);  //Low position in the vector child

	for (int j = low; j < high; j++)
	{
		if (values[j] <= pivot) //If current element is smaller or equal to pivot 
		{
			Low++; //Increment Low element index
			std::swap(values[Low], values[j]);
		}
	}

	std::swap(values[Low + 1], values[high]);

	return (Low + 1);
}
void Sorter::QuickSortHelper(std::vector<unsigned int>& values, int low, int high)
{
	if (low < high)
	{
		//Position for the new vector partition
		int position = QuickSortSwapper(values, low, high);

		//Separately sort both sides of the vector
		QuickSortHelper(values, low, position - 1);
		QuickSortHelper(values, position + 1, high);
	}
}
void Sorter::QuickSort(std::vector<unsigned int>& values)
{
	QuickSortHelper(values, 0, values.size() - 1);
}

void Sorter::MergeSortHelper(std::vector<unsigned int>& values, int left, int right)
{
	if (left < right)
	{
		unsigned int middle = left + (right - left) / 2;

		//Sort first and second halves 
		MergeSortHelper(values, left, middle);
		MergeSortHelper(values, middle + 1, right);

		Merge(values, left, middle, right);
	}
}
void Sorter::Merge(std::vector<unsigned int>& values, int left, int middle, int right)
{
	//Set children limits
	int leftChild = middle - left + 1;
	int rightChild = right - middle;

	//Temporal child vectors
	std::vector <unsigned int> LeftChild(leftChild);
	std::vector <unsigned int> RightChild(rightChild);

	//Copy orginal data to children
	int i, j;
	for (i = 0; i < leftChild; i++)
	{
		LeftChild[i] = values[left + i];
	}
	for (j = 0; j < rightChild; j++)
	{
		RightChild[j] = values[middle + 1 + j];
	}

	//Sort children values
	i = 0;	j = 0;
	while (i < leftChild && j < rightChild)
	{
		if (LeftChild[i] <= RightChild[j])
		{
			values[left] = LeftChild[i];
			i++;
		}
		else
		{
			values[left] = RightChild[j];
			j++;
		}

		left++;
	}

	//Copy sorted childs into the original vector
	while (i < leftChild)
	{
		values[left] = LeftChild[i];
		i++;
		left++;
	}
	while (j < rightChild)
	{
		values[left] = RightChild[j];
		j++;
		left++;
	}
}
void Sorter::MergeSort(std::vector<unsigned int>& values)
{
	MergeSortHelper(values, 0, values.size() -1);
}