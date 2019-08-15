#include "Headers.h"
#include "Timer.h"

#define Dynamic

std::vector<std::string> 
GetSubSequences(std::string sequence) {

	int n = sequence.length();															
	int numSubSequences = pow(2, n);												
	std::vector<std::string> subSequences;									

	for (size_t i = 1; i < numSubSequences; i++) {					 
		std::string subSequence;															
		for (size_t j = 0; j < n; j++){												
			if (i & (1 << j)) {																	
				subSequence += sequence[j];									
			}
		}
		subSequences.push_back(subSequence);									
	}
	return subSequences;																		
}

std::string 
CompareSubsequenses(const std::vector <std::string>& sequenceA, const std::vector <std::string>& sequenceB) {
	std::string lcs;

	for (size_t i = 0; i < sequenceA.size(); i++) {
		for (size_t j = 0; j < sequenceB.size(); j++) {
			if (sequenceA[i] == sequenceB[j]) {
 				if (lcs.length() < sequenceA[i].length()) {
					lcs = sequenceA[i];
				}
			}
		}
	}
	return lcs;
}

//LCS Brute force
void 
LCS(std::string X, std::string Y) {
	
	std::vector<std::vector<int>> L;

	L.resize(X.length() + 1);
	
	for (size_t i = 0; i < L.size(); i++) {
		L[i].resize(Y.length() + 1);
	}

	for (size_t i = 0; i < L.size(); i++) {
		for (size_t j = 0; j < L[i].size(); j++) {
			if (i == 0 || j == 0) {
				L[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else {
				L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
			}
		}
	}

	int index = L[L.size() - 1][L[0].size() - 1];

	std::string lcs;
	lcs.resize(index + 1, ' ');

	int i = X.size();
	int j = Y.size();

	while (i > 0 and j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1] = X[i - 1];
			i -= 1;
			j -= 1;
			index -= 1;
		}
		else if (L[i - 1][j] > L[i][j - 1]) {
			i -= 1;
		}
		else {
			j -= 1;
		}
	}

	std::cout << "La subsecuencia mas larga comun de " + X + " y de " + Y + " es: " + lcs + "\n";
}

int main() {
	Timer timer;

	std::string X = "TTCGCATCGGGTTG";
	std::string Y = "TGACCGTGTGTCACG";

	timer.Start();

#ifdef Dynamic
	std::cout << "---Dynamic Programming---\n";
	LCS(X, Y);
	timer.End();
#else
	std::cout << "---Brute Force---\n";

	std::vector<std::string> subSequence1 = GetSubSequences(X);
	std::vector<std::string> subSequence2 = GetSubSequences(Y);
	std::string common = CompareSubsequenses(subSequence1, subSequence2);
	std::cout << "La subsecuencia mas larga comun de " + X + " y de " + Y + " es: " + common + "\n";
	timer.End();

#endif
	return 0;
}
