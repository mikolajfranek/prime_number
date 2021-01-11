#include "../../Main.h"

#ifndef ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_
#define ALGORITHMS_PRIMESBELOWLIMIT_SIEVEOFERATOSTHENES_H_

namespace AlgorithmsPrimesBelowUpperBound {
	class SieveOfEratosthenes : public AlgorithmsAbstracts::IPrimesBelowUpperBound {
	public:
		SieveOfEratosthenes();
		virtual ~SieveOfEratosthenes();
		vector<unsigned long long>* GetPrimes(unsigned long long upperBound);
	};
}

#endif
