#include "../Configurations/MyConfiguration.h"
#include "Algorithm.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

class QuadraticSieve {
public:
	static void Factor(string n);






private:
	static vector<int> GetPrimeListBelowN(int b);
	static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
	static void DivideSieve(mpz_t *sieve, int sizeOfSieve, int from, int step);
	static void Tonelli_Shanks(mpz_t n, mpz_t p);
	static vector<vector<float>> GetIdentityMatrix(int n);






	static void PrintMatrix(vector<vector<float>> A);
	static void Gaussian_Triangular(vector<vector<float>> &A, vector<int> &pivot, int &det, bool &err);
	static void Gaussian_Solve(vector<vector<float>> &A, vector<int> &pivot, vector<float> &b);


	static bool InputHasFormPowPToM(mpz_t n);


	//static bool EulerCriterion(mpz_t a, mpz_t p, mpz_t exp, mpz_t tem);
};

#endif
