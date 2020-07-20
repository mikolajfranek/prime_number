#include "../../MyHeader.h"

#ifndef ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_
#define ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_

namespace PrimesBelowLimit {
	class SieveOfEratosthenes {
	public:
		static vector<unsigned long long>* GetPrimes(unsigned long long limit);
	};
}

#endif
