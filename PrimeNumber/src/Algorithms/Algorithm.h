#include "../Configurations/MyConfiguration.h"

#ifndef ALGORITHMS_ALGORITHM_H_
#define ALGORITHMS_ALGORITHM_H_

class Algorithm {
public:
	Algorithm();
	static void CheckResult(mpz_t n, mpz_t p, mpz_t q);
	virtual ~Algorithm();
};

#endif
