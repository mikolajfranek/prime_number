#include "MyHeader.h"

#ifndef CONFIGURATIONS_MYHELPER_H_
#define CONFIGURATIONS_MYHELPER_H_

class MyHelper {
public:
	//other
	static void CheckResult(mpz_t n, mpz_t q, mpz_t p);
	static void MallocVector(mpz_t **v, unsigned long long n);
	static void ReallocVector(mpz_t **v, unsigned long long n);
	static void DivideSieve(mpz_t *sieve, unsigned long long sizeOfSieve, unsigned long long from, unsigned long long step);
	static vector<vector<unsigned long long>> GetCombination(unsigned long long n, unsigned long long k);
	//prime
	static vector<unsigned long long> GetPrimesBelowN(unsigned long long b);
	//matrix
	static void PrintMatrix(vector<vector<bool>> A);
	static vector<vector<bool>> GetIdentityMatrix(unsigned long long n);







	static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
	static bool InputHasFormPowPToM(mpz_t n);
	static string GetSemiPrime(int numberOfDigits);
};

#endif
