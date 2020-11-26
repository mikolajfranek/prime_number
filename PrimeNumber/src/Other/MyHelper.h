#include "../Main.h"

#ifndef CONFIGURATIONS_MYHELPER_H_
#define CONFIGURATIONS_MYHELPER_H_

namespace Other {
	class MyHelper {
	public:
		static string GetPrime(unsigned short numberOfDigits);
		static string GetSemiPrime(unsigned short numberOfDigits);
		static void CheckResult(mpz_t n, mpz_t q, mpz_t p);
		static void Malloc(mpz_t **v, unsigned long long n);
		static void Realloc(mpz_t **v, unsigned long long n);
		static void DivideSieve(vector<Elements::ElementOfSieve> sieve, unsigned long long sizeOfSieve, unsigned long long *from, unsigned long long step);
		static void PrintMatrix(vector<vector<bool>> matrix);
		static vector<vector<bool>> GetIdentityMatrix(unsigned long long n);
		static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
		static unsigned long GetUpperBoundOfPrimes(string n);
	};
}

#endif
