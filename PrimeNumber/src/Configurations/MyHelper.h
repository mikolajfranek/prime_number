#include "MyHeader.h"

#ifndef CONFIGURATIONS_MYHELPER_H_
#define CONFIGURATIONS_MYHELPER_H_

class MyHelper {
public:
	//other
	static void CheckResult(mpz_t n, mpz_t q, mpz_t p);
	static void InitializeVector(mpz_t **v, unsigned long long n);
	//prime
	static vector<unsigned long long> GetPrimesBelowN(unsigned long long b);









	static void DivideSieve(mpz_t *sieve, unsigned long long sizeOfSieve, unsigned long long from, unsigned long long step);



	static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);

	static vector<vector<int>> GetCombination(int n, int k);
	static bool InputHasFormPowPToM(mpz_t n);

	//matrix
	static vector<vector<float>> GetIdentityMatrix(int n);
	static void PrintMatrix(vector<vector<float>> A);
	static void Gaussian_SolveMod2(vector<vector<float>> &A, vector<vector<float>> &b);



	static string GetSemiPrime(int numberOfDigits);

};

#endif
