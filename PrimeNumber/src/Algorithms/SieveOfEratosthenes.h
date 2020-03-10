#include "../Configurations/MyConfiguration.h"

#ifndef ALGORITHMS_SIEVEOFERATOSTHENES_H_
#define ALGORITHMS_SIEVEOFERATOSTHENES_H_

class SieveOfEratosthenes {
public:
	SieveOfEratosthenes();
	void Factor(mpz_t n);
	virtual ~SieveOfEratosthenes();
};

#endif
