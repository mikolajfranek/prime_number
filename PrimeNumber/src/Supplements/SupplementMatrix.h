#include "../Configurations/MyConfiguration.h"

#ifndef SUPPLEMENTS_SUPPLEMENTMATRIX_H_
#define SUPPLEMENTS_SUPPLEMENTMATRIX_H_

class SupplementMatrix {
public:
	static vector<vector<float>> GetIdentityMatrix(int n);
	static void PrintMatrix(vector<vector<float>> A);
	static void Gaussian_SolveMod2(vector<vector<float>> &A, vector<vector<float>> &b);
};

#endif
