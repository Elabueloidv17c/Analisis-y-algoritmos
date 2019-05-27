#pragma once
#include "Headers.h"

class Sorter
{
public:

	static void DecreasingGen(std::vector<unsigned int>& values, const unsigned int& size);
	static void IncreasingGen(std::vector<unsigned int>& values, const unsigned int& size);
	static void RandomGen(std::vector<unsigned int>& values, const unsigned int& size);
	static void Print(std::vector<unsigned int>& values);

	static void BubbleSort(std::vector<unsigned int>& values);
	static void InsertionSort(std::vector<unsigned int>& values);

	static unsigned int QuickSortSwapper(std::vector<unsigned int>& values, int low, int high);
	static void QuickSortHelper(std::vector<unsigned int>& values, int low, int high);
	static void QuickSort(std::vector<unsigned int>& values);

	static void MergeSortHelper(std::vector<unsigned int>& values, int left, int right);
	static void Merge(std::vector<unsigned int>& values, int left, int middle, int right);
	static void MergeSort(std::vector<unsigned int>& values);

	Sorter() = default;
	~Sorter() = default;
};

