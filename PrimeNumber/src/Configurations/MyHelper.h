#include "MyHeader.h"

#ifndef CONFIGURATIONS_MYHELPER_H_
#define CONFIGURATIONS_MYHELPER_H_

class MyHelper {
public:
	//other
	static void CheckResult(mpz_t n, mpz_t p, mpz_t q);
	static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
	static void DivideSieve(mpz_t *sieve, int sizeOfSieve, int from, int step);
	static vector<vector<int>> GetCombination(int n, int k);
	static bool InputHasFormPowPToM(mpz_t n);

	//matrix
	static vector<vector<float>> GetIdentityMatrix(int n);
	static void PrintMatrix(vector<vector<float>> A);
	static void Gaussian_SolveMod2(vector<vector<float>> &A, vector<vector<float>> &b);

	//prime
	static string GetSemiPrime(int numberOfDigits);
	static vector<int> GetPrimeListBelowN(int b);
};

#endif
