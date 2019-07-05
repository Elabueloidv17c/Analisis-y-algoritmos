#pragma once
#include "Headers.h"
#include <vector>
#include <string>
class Hash
{
	int* m_primeNumbers;
	std::vector<std::vector<float>> m_table;
	int m_currentPrime;
	int m_hashA;
	int m_hashB;

public:

	Hash();
	~Hash();

	std::vector<std::vector<float>>* Get();
	int GetRandomPrime();


	void Initialize(int size);
	void Multiplication(float value);
	void Universal(float value);
	void Division(float value);
};