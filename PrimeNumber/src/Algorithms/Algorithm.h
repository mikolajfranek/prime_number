#include "../Configurations/MyConfiguration.h"

#ifndef ALGORITHMS_ALGORITHM_H_
#define ALGORITHMS_ALGORITHM_H_

class Algorithm {
public:
	Algorithm();
	static void CheckResult(mpz_t n, mpz_t p, mpz_t q);
	static void CheckResult(mpf_t n, mpf_t p, mpf_t q);
	virtual ~Algorithm();
};

#endif
