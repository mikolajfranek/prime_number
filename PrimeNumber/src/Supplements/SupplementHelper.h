#include "../Configurations/MyConfiguration.h"

#ifndef SUPPLEMENTS_SUPPLEMENTHELPER_H_
#define SUPPLEMENTS_SUPPLEMENTHELPER_H_

class SupplementHelper {
public:
	static void CheckResult(mpz_t n, mpz_t p, mpz_t q);
	static void PowCExpD(mpz_t r, mpz_t c, mpz_t d);
	static void DivideSieve(mpz_t *sieve, int sizeOfSieve, int from, int step);
	static vector<vector<int>> GetCombination(int n, int k);
	static bool InputHasFormPowPToM(mpz_t n);
};

#endif
